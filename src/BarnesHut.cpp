#include "integration/RK4.hpp"
#include "model/falling_object.hpp"

#include "window/window.hpp"
#include "element/square.hpp"
#include <iostream>
#include <SDL2/SDL.h>

int main() {
  FallingObject ball(1,4);
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

  Window scenario(800, 800, "Testing");
  SDL_Window *win;
  scenario.GetWindow(win);
  scenario.CreateWindow();
  Square box(win);
  for (int i = 0; i < 10; ++i) {
    double zero = 0.0e0;
    box.DrawElement<double>(output[i][0],output[i][1], zero);
  }
}
