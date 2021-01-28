#ifndef N_BODY_DISTRIBUTION_H
#define N_BODY_DISTRIBUTION_H

#include <random>
#include <cmath>
#include <stdexcept>

class NBodyDistribution {
  // Generates initial conditions for N-body simulation
 public:
  NBodyDistribution();
  ~NBodyDistribution();

  void Planetary(double* state, double* masses, int num_bodies, double radius);
  void Cluster(double* state, double* masses, int start_body, int num_bodies,
               int x, int y, int z, double radius);
private:
  int RandomSign();
};

#endif