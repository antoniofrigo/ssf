#include <cmath>
#include <random>
#include "barnes_hut/Constant.hpp"
#include "barnes_hut/InitialCondition.hpp"

void InitialCondition::Planetary(double state[], double mass_center, double min_radius, double max_radius){
  std::default_random_engine generator;
  std::uniform_real_distribution <double> uni_dist(min_radius,max_radius);
  // double x = uni_dist(generator);
  // double y = uni_dist(generator);
  // double z = 0.0e0;

  // double vx = - sqrt(Constant::G * mass_center * y * y/ pow(x*x + y*y, 1.5));
  // double vy = sqrt(Constant::G * mass_center * x * x/ pow(x*x + y*y, 1.5));
  // double vz = 0.0e0;
  //
  double x = 1.0;
  double y = 0.0;
  double z = 0.0;
  double vx = 0.0;
  double vy = 2.0 * 3.14;
  double vz = 0.0;

  state[0] = x;
  state[1] = y;
  state[2] = z;
  state[3] = vx;
  state[4] = vy;
  state[5] = vz;
}

void InitialCondition::Galactic(double state[], double max_radius){
  std::default_random_engine generator;
  std::uniform_real_distribution <double> uni_dist(0,max_radius);
  std::normal_distribution <double> norm_dist(0,max_radius/50.0);

  double x = uni_dist(generator);
  double y = uni_dist(generator);
  double z = norm_dist(generator);

  double vx = - Constant::G * y/ pow(x*x + y*y, 1.5);
  double vy = Constant::G * x/ pow(x*x + y*y, 1.5);
  double vz = 0.0e0;

  state[0] = x;
  state[1] = y;
  state[2] = z;
  state[3] = vx;
  state[4] = vy;
  state[5] = vz;
}

void InitialCondition::Cluster(double state[], double interval){
  std::default_random_engine generator;
  std::exponential_distribution <double> exp_dist(interval);

  double x = exp_dist(generator);
  double y = exp_dist(generator);
  double z = exp_dist(generator);

  double vx = Constant::G * y/ pow(x*x + y*y + z*z, 1.5);
  double vy = Constant::G * z/ pow(x*x + y*y + z*z, 1.5);
  double vz = Constant::G * x/ pow(x*x + y*y + z*z, 1.5);

  state[0] = x;
  state[1] = y;
  state[2] = z;
  state[3] = vx;
  state[4] = vy;
  state[5] = vz;
}
