#include "scenario/falling_object_scenario.hpp"

FallingObjectScenario::FallingObjectScenario(int iterations, double timestep)
    : s_rows(iterations),
      s_cols(4), 
      s_set_initial(false),
      h(timestep),
      model(1, s_cols),
      integrator(&model, s_cols),
      window() {
  state = new double *[s_rows + 1];
  for (int i = 0; i < s_rows + 1; ++i) {
    state[i] = new double[s_cols];
  }

  initial = new double[s_cols];
}

FallingObjectScenario::~FallingObjectScenario() {
  for (int i = 0; i < s_rows + 1; ++i) {
    delete[] state[i];
  }
  delete[] state;
  delete[] initial;
}

void FallingObjectScenario::SetInitial(double *initial_cond) {
  for (int i = 0; i < s_cols; ++i) {
    initial[i] = initial_cond[i];
    state[0][i] = initial_cond[i];
  }
  model.SetInitial(initial_cond);
  integrator.SetStepSize(h);
  s_set_initial = true;
}

void FallingObjectScenario::Run() {
  if (s_set_initial == false) {
    throw std::runtime_error("Initial condition not set in window.");
  }

  for (int i = 1; i < s_rows + 1; ++i) {
    integrator.ComputeStep(state[i - 1], state[i]);
  }

  window.SetWindowDimension(1000, 1000);
  window.SetWindowFPS(40);
  window.SetWindowIterations(s_rows + 1);
  window.SetState(state);
  window.CreateWindow();
}

void FallingObjectScenario::PrintState() const {
  for (int i = 0; i < s_rows + 1; ++i) {
    for (int j = 0; j < s_cols; ++j) {
      std::cout << state[i][j] << " ";
    }
    std::cout << std::endl;
  }
}