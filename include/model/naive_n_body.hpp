#ifndef NAIVE_N_BODY_H
#define NAIVE_N_BODY_H

#include <cstring>
#include <random>
#include <stdexcept>
#include <string>

#include "model/model.hpp"

class NaiveNBody : public Model {
  // Model for naive N-body simulation
 public:
  NaiveNBody(int id, int num_bodies);
  ~NaiveNBody();

  void GenerateInitial(double *output, std::string name); // Generates initial conditions
  void EvaluateAt(double *output, double *state, double time);

 private:
  int m_bodies; // Number of bodies

  double *m_masses; // Array of masses
};

#endif