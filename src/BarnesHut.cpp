#include "scenario/naive_n_body_scenario.hpp"

int main() {
  NaiveNBodyScenario scenario(10000, 10000, 2);
  scenario.SetInitial();
  scenario.Run();
}
