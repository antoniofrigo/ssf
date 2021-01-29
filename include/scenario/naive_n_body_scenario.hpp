#ifndef NAIVE_N_BODY_SCENARIO
#define NAIVE_N_BODY_SCENARIO

#include "integration/RK4.hpp"
#include "model/naive_n_body.hpp"
#include "window/naive_n_body_window.hpp"

class NaiveNBodyScenario {
  // Scenario for naive N body simulation
 public:
  NaiveNBodyScenario(int iterations, double timestep, int num_bodies);
  ~NaiveNBodyScenario();

  void SetInitial();
  void PrintState() const;
  void Run();

 private:
  int s_rows; // Number of rows (total iterations over time)
  int s_cols; // Number of dimensions (equations to integrate)

  bool s_set_initial; // Whether initial conditions are set

  double h; // Timestep
  double time; // Current time
  double *initial; // Initial state
  double **state; // All states, state[iteration #][equation #]

  NaiveNBody model;
  RK4 integrator;
  NaiveNBodyWindow window;
};

#endif