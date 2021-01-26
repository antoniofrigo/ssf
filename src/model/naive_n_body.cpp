#include "model/naive_n_body.hpp"

#include <iostream>

NaiveNBody::NaiveNBody(int id, int num_bodies)
    : Model(id, 6 * num_bodies), m_bodies(num_bodies) {
  m_masses = new double[num_bodies];
}

NaiveNBody::~NaiveNBody() { delete[] m_masses; }

void NaiveNBody::GenerateInitial(double *output, std::string name) {
  double x, y, z;
  double vx, vy, vz;

  if (name == "planetary") {
    if (m_bodies < 2) {
      throw std::runtime_error("Insufficient bodies for planetary scenario.");
    }

    // Define central object
    double central_mass = 1.989e30;
    m_masses[0] = central_mass;
    output[0] = 0.0;
    output[1] = 0.0;
    output[2] = 0.0;
    output[3 * m_bodies + 0] = 0.0;
    output[3 * m_bodies + 1] = 0.0;
    output[3 * m_bodies + 2] = 0.0;

    double mass = 1.9e28;

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(1e10, 1e12);

    for (int i = 1; i < m_bodies; ++i) {
      x = distribution(generator);
      y = 0.0e0;
      z = 0.0e0;

      vx = 0.0;
      vy = sqrt(6.67e-11 * central_mass / x);
      vz = 0.0;

      m_masses[i] = mass;
      output[3 * i + 0] = x;
      output[3 * i + 1] = y;
      output[3 * i + 2] = z;
      output[3 * (m_bodies + i) + 0] = vx;
      output[3 * (m_bodies + i) + 1] = vy;
      output[3 * (m_bodies + i) + 2] = vz;
    }
  }
}

void NaiveNBody::EvaluateAt(double *output, double *state, double time) {
  (void)time;
  for (int i = 0; i < m_bodies; ++i) {
    output[3 * i + 0] = state[3 * (m_bodies + i) + 0];
    output[3 * i + 1] = state[3 * (m_bodies + i) + 1];
    output[3 * i + 2] = state[3 * (m_bodies + i) + 2];
    output[3 * (m_bodies + i) + 0] = 0.0e0;
    output[3 * (m_bodies + i) + 1] = 0.0e0;
    output[3 * (m_bodies + i) + 2] = 0.0e0;
  }

  double dx, dy, dz;
  double f_modified;
  double r_sq;

  for (int i = 0; i < m_bodies; ++i) {
    for (int j = 0; j < m_bodies; ++j) {
      if (i == j) {
        continue;
      }

      dx = state[3 * j + 0] - state[3 * i + 0];
      dy = state[3 * j + 1] - state[3 * i + 1];
      dz = state[3 * j + 2] - state[3 * i + 2];

      r_sq = dx * dx + dy * dy + dz * dz + 1e12;

      f_modified = 6.67e-11 * m_masses[j] / pow(r_sq, 1.5);
      output[3 * (m_bodies + i) + 0] += f_modified * dx;
      output[3 * (m_bodies + i) + 1] += f_modified * dy;
      output[3 * (m_bodies + i) + 2] += f_modified * dz;
    }
  }
}