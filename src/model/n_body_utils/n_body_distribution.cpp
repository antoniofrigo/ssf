#include "model/n_body_utils/n_body_distribution.hpp"
#include <iostream>
NBodyDistribution::NBodyDistribution() {}

NBodyDistribution::~NBodyDistribution() {}

void NBodyDistribution::Planetary(double* state, double* masses, int num_bodies, double radius) {
  // Defines a planar planetary system containing a central mass and num_bodies
  // - 1 outer bodies with randomly generated positions and masses
  if (num_bodies < 2) {
    throw std::runtime_error("NBodyDistribution: num_bodies < 2");
  }

  std::default_random_engine generator;
  std::uniform_real_distribution<double> radius_distribution(radius / 100,
                                                             radius);
  std::uniform_real_distribution<double> outer_mass_distribution(1e26, 1e29);
  std::uniform_real_distribution<double> central_mass_distribution(1e30, 1e32);

  // Defines central mass
  double central_mass = central_mass_distribution(generator);
  masses[0] = central_mass;
  state[0] = 0.0e0;
  state[1] = 0.0e0;
  state[2] = 0.0e0;
  state[3 * num_bodies + 0] = 0.0e0;
  state[3 * num_bodies + 1] = 0.0e0;
  state[3 * num_bodies + 2] = 0.0e0;

  // Defines other masses
  double v, r;
  double x, y, z;
  double vx, vy, vz;
  double mass;

  // Silences unused variable errors
  (void)x,(void)y,(void)z;
  (void)vx,(void)vy,(void)vz;
  (void)mass;

  for (int i = 1; i < num_bodies; ++i) {
    mass = outer_mass_distribution(generator);
    masses[i] = mass;

    x = RandomSign() * radius_distribution(generator);
    y = RandomSign() * radius_distribution(generator);
    z = 0.0e0;

    r = sqrt(x * x + y * y);
    v = sqrt(6.67e-11 * central_mass / r);

    vx = -y * v / r;
    vy = x * v / r;
    vz = 0.0e0;

    state[3 * i + 0] = x;
    state[3 * i + 1] = y;
    state[3 * i + 2] = z;
    state[3 * (num_bodies + i) + 0] = vx;
    state[3 * (num_bodies + i) + 1] = vy;
    state[3 * (num_bodies + i) + 2] = vz;
  }
}

void NBodyDistribution::Cluster(double* state, double* masses, int start_body,
                                int num_bodies, int x0, int y0, int z0,
                                double radius) {
  std::default_random_engine generator;
  std::exponential_distribution<double> radius_distribution(radius);
  std::uniform_real_distribution<double> mass_distribution(1e30, 1e31);

  // Defines central mass
  double central_mass = 1e37;
  masses[0] = central_mass;
  state[3 * start_body + 0] = x0;
  state[3 * start_body + 1] = y0;
  state[3 * start_body + 2] = z0;
  state[3 * (start_body + num_bodies) + 0] = 0.0e0;
  state[3 * (start_body + num_bodies) + 1] = 0.0e0;
  state[3 * (start_body + num_bodies) + 2] = 0.0e0;

  // Defines other masses
  double v, r;
  double x, y, z;
  double vx, vy, vz;
  double mass;

  // Silences unused variable errors
  (void)x,(void)y,(void)z;
  (void)vx,(void)vy,(void)vz;
  (void)mass;

  for (int i = start_body + 1; i < start_body + num_bodies; ++i) {
    mass = mass_distribution(generator);
    masses[i] = mass;

    x = RandomSign() * radius_distribution(generator);
    y = RandomSign() * radius_distribution(generator);
    z = RandomSign() * radius_distribution(generator);

    r = sqrt(x * x + y * y + z * z);
    v = sqrt(6.67e-11 * 5 * central_mass / r);

    vx = -y * v / r;
    vy = x * v / r;
    vz = 0.0e0;

    state[3 * i + 0] = x + x0;
    state[3 * i + 1] = y + y0;
    state[3 * i + 2] = z + z0;
    state[3 * (num_bodies + i) + 0] = x;
    state[3 * (num_bodies + i) + 1] = y;
    state[3 * (num_bodies + i) + 2] = z;
  }
}

int NBodyDistribution::RandomSign() {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0,1);
  return (distribution(generator) * 2) - 1;
}