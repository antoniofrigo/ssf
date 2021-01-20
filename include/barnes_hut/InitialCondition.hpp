#ifndef INITIAL_H
#define INITIAL_H

namespace InitialCondition {
  // Generates the initial positions and velocities of 
  // different scenarios:
  //  Planetary: Planets with uniform probability distribution
  //  Galactic: Planets with uniform probability distribution
  //  Cluster: Planets with uniform probability distribution

  void Planetary(double state[], double mass_center, double min_radius, double max_radius);
  void Galactic(double state[], double max_radius);
  void Cluster(double state[], double interval);
}

#endif
