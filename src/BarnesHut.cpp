#include "scenario/falling_object_scenario.hpp"

int main() {
  FallingObjectScenario scenario(200, 0.1);
  double initial[4] = {0.0, 0.0, 10.0, 0.0};
  scenario.SetInitial(initial);
  scenario.Run();
}
