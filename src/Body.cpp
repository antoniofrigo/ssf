#include <cmath>
#include "barnes_hut/Body.hpp"
#include "barnes_hut/Constant.hpp"
#include "barnes_hut/RK4.hpp"
#include <iostream>


void Body::get_r_square(double &rsq, Body &obj2){
  double diff_x = obj2.state_old[0] - (this->state_old[0]);
  double diff_y = obj2.state_old[1] - (this->state_old[1]);
  double diff_z = obj2.state_old[2] - (this->state_old[2]);
  rsq = diff_x * diff_x + diff_y * diff_y + diff_z * diff_z;
}

void Body::update_acceleration(Body &obj2){
  // Updates the acceleration due to the force between two bodies
  double rsq;
  Body::get_r_square(rsq, obj2);

  for (int i = 6; i < 9; ++i) {
    this->state[i] += Constant::G * obj2.m * (obj2.state_old[i-6] - (this->state_old[i-6])) / pow(rsq, 1.5e0);
  }
}

void Body::update_position(Body &obj1, double &dt){
  // Updates body position using 4th Order Runge Kutta

  RK4::RK4Solver(obj1.state, dt, dt);
  for (int i = 0; i < 9; ++i) {
    obj1.state_old[i] = obj1.state[i];
  }
}

void Body::reset_force(){
  this->state[6] = 0.0e0;
  this->state[7] = 0.0e0;
  this->state[8] = 0.0e0;
}
