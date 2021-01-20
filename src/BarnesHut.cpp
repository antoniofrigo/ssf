#include <iostream>
#include "barnes_hut/InitialCondition.hpp"
#include "barnes_hut/Constant.hpp"
#include "barnes_hut/Body.hpp"
#include <fstream>

int main()
{
  std::cout << "Starting Barnes-Hut Simulation..." << std::endl;
  std::ofstream out ("output.dat");

  Body arr[2];
  arr[0].m = 1;
  arr[1].m = 0.01;
  InitialCondition::Planetary(arr[1].state, 1, 1, 1);

  for (int i = 0; i < 9; ++i) {
    arr[1].state_old[i] = arr[1].state[i];
  }

  double t = 0.0;
  // double tstop = 3/3650.0;
  double tstop = 2;
  double dt = 1/3650.0;

  while (t < tstop){
    for (int i = 0; i < 2; ++i) {
      arr[i].reset_force();
      for (int j = 0; j < 2; ++j) {
        if (i == j) {continue;}
        arr[i].update_acceleration(arr[j]);
      }
    }

    for (int i = 1; i < 2; ++i) {
      out << arr[i].state[0] << " " << arr[i].state[1] << " " << arr[i].state[2] << " ";
      out << arr[i].state[3] << " " << arr[i].state[4] << " " << arr[i].state[5] << " ";
      out << arr[i].state[6] << " " << arr[i].state[7] << " " << arr[i].state[8] << std::endl;
      arr[i].update_position(arr[i], dt);
      out << arr[i].state[0] << " " << arr[i].state[1] << " " << arr[i].state[2] << " ";
      out << arr[i].state[3] << " " << arr[i].state[4] << " " << arr[i].state[5] << " ";
      out << arr[i].state[6] << " " << arr[i].state[7] << " " << arr[i].state[8] << std::endl;
    }

    t += dt;
  }

  return 0;
}
