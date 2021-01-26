#ifndef NAIVE_N_BODY
#define NAIVE_N_BODY

#include <cstring>
#include <random>
#include <stdexcept>
#include <string>

#include "model/model.hpp"

class NaiveNBody : public Model {
 public:
  NaiveNBody(int id, int num_bodies);
  ~NaiveNBody();

  void GenerateInitial(double *output, std::string name);
  void EvaluateAt(double *output, double *state, double time);

 private:
  int m_bodies;

  double *m_masses;
};

#endif