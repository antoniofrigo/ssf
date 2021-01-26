#ifndef NAIVE_N_BODY_SCENARIO
#define NAIVE_N_BODY_SCENARIO

#include "integration/RK4.hpp"
#include "model/naive_n_body.hpp"
#include "window/naive_n_body_window.hpp"

class NaiveNBodyScenario {
 public:
  NaiveNBodyScenario(int iterations, double timestep, int num_bodies);
  ~NaiveNBodyScenario();

  void SetInitial();
  void PrintState() const;
  void Run();

 private:
  int s_rows;
  int s_cols;

  bool s_set_initial;

  double h;
  double time;
  double *initial;
  double **state;

  NaiveNBody model;
  RK4 integrator;
  NaiveNBodyWindow window;
};

#endif