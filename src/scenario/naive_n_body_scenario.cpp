#include "scenario/naive_n_body_scenario.hpp"

NaiveNBodyScenario::NaiveNBodyScenario(int iterations, double timestep, int num_bodies)
    : s_rows(iterations),
      s_cols(6 * num_bodies), 
      s_set_initial(false),
      h(timestep),
      model(1, num_bodies),
      integrator(&model, s_cols),
      window() {
  state = new double *[s_rows + 1];
  for (int i = 0; i < s_rows + 1; ++i) {
    state[i] = new double[s_cols];
  }

  initial = new double[s_cols];

  window.SetBodies(num_bodies);
}

NaiveNBodyScenario::~NaiveNBodyScenario() {
  for (int i = 0; i < s_rows + 1; ++i) {
    delete[] state[i];
  }
  delete[] state;
  delete[] initial;
}

void NaiveNBodyScenario::SetInitial() {
  model.GenerateInitial(initial, "planetary");
  for (int i = 0; i < s_cols; ++i) {
    state[0][i] = initial[i];
  }
  model.SetInitial(initial);
  integrator.SetStepSize(h);
  s_set_initial = true;
}

void NaiveNBodyScenario::Run() {
  if (s_set_initial == false) {
    throw std::runtime_error("Initial condition not set in window.");
  }

  for (int i = 1; i < s_rows + 1; ++i) {
    integrator.ComputeStep(state[i - 1], state[i]);
  }

  window.SetWindowDimension(1000, 1000);
  window.SetWindowFPS(60);
  window.SetWindowIterations(s_rows + 1);
  window.SetState(state);
  window.CreateWindow();
}

void NaiveNBodyScenario::PrintState() const {
  for (int i = 0; i < s_rows + 1; ++i) {
    for (int j = 0; j < s_cols; ++j) {
      std::cout << state[i][j] << " ";
    }
    std::cout << std::endl;
  }
}