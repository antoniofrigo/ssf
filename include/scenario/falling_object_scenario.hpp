#ifndef FALLING_OBJECT_SCENARIO
#define FALLING_OBJECT_SCENARIO

#include "integration/RK4.hpp"
#include "model/falling_object.hpp"
#include "window/falling_object_window.hpp"

class FallingObjectScenario {
  // Scenario for falling object
 public:
  FallingObjectScenario(int iterations, double timestep);
  ~FallingObjectScenario();

  void SetInitial(double *initial_cond);
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

  FallingObject model;
  RK4 integrator;
  FallingObjectWindow window;
};

#endif