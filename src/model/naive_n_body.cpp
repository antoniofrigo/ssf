#include "model/naive_n_body.hpp"

#include "model/n_body_utils/n_body_distribution.hpp"

NaiveNBody::NaiveNBody(int id, int num_bodies)
    : Model(id, 6 * num_bodies), m_bodies(num_bodies) {
  m_masses = new double[num_bodies];
}

NaiveNBody::~NaiveNBody() { delete[] m_masses; }

void NaiveNBody::GenerateInitial(double *output, std::string name) {
  // Generates initial conditions for N-body simulation
  double x, y, z;
  double vx, vy, vz;

  (void)x, (void)y, (void)z;
  (void)vx, (void)vy, (void)vz;
  NBodyDistribution distribution;

  if (name == "planetary") {
    distribution.Planetary(output, m_masses, m_bodies, 1e12);
  } else if (name == "cluster") {
    distribution.Cluster(output, m_masses, 0, m_bodies, 0, 0, 0, 1e12);
  }
}

void NaiveNBody::EvaluateAt(double *output, double *state, double time) {
  // Find derivative array at the current time
  // Output: 1D array containing vec(dx), vec(dv)
  // State: 1D array containing current state of simulation
  // Time: Time coordinate
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