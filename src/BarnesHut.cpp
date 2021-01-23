#include <SDL2/SDL.h>

#include <iostream>

#include "element/square.hpp"
#include "integration/RK4.hpp"
#include "model/falling_object.hpp"
#include "window/window.hpp"

int main() {
  FallingObject ball(1, 4);
  RK4 integrator(&ball, 4);
  integrator.SetStepSize(1.0);
  double initial[4] = {0.0, 0.0, 2.0, 0.0};
  double output[10][4];
  ball.SetInitial(initial);

  integrator.SetInitial(initial);

  for (int i = 0; i < 10; ++i) {
    integrator.ComputeStep();
    integrator.GetState(output[i]);
  }

  Window testing(1000, 1000);
  char* title = "HERE";
  testing.SetWindowTitle(title);
  testing.OpenWindow();
}
