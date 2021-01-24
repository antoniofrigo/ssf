#ifndef FALLING_OBJECT_SCENARIO
#define FALLING_OBJECT_SCENARIO

#include "integration/RK4.hpp"
#include "model/falling_object.hpp"
#include "window/falling_object_window.hpp"

class FallingObjectScenario {
 public:
  FallingObjectScenario(int iterations, double timestep);
  ~FallingObjectScenario();

  void SetInitial(double *initial_cond);
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

  FallingObject model;
  RK4 integrator;
  FallingObjectWindow window;
};

#endif