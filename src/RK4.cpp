#include "barnes_hut/RK4.hpp"
#include "barnes_hut/Constant.hpp"
#include <iostream>
#include <cmath>

void RK4::RK4Solver(double *state, double &dt, double &tstop){
  // Generic Runge-Kutta Solver
  int numeqs = RK4::NumEqs();
  double t = 0.0e0;

  // This could probably be done more efficiently by 
  // keeping these arrays associated with each object
  double *k1 = nullptr;
  double *k2 = nullptr;
  double *k3 = nullptr;
  double *k4 = nullptr;
  double *y1 = nullptr;
  double *y2 = nullptr;
  double *y3 = nullptr;
  double *rhs = nullptr;
  k1 = new double[numeqs];
  k2 = new double[numeqs];
  k3 = new double[numeqs];
  k4 = new double[numeqs];
  y1 = new double[numeqs];
  y2 = new double[numeqs];
  y3 = new double[numeqs];
  rhs = new double[numeqs];

  while (t < tstop){
    RK4::GetRHS(state, rhs, t);
		for (int i = 0; i < numeqs; ++i) {
			k1[i] = dt * rhs[i];
			y1[i] = state[i] + 0.5 * k1[i];
		}

    RK4::GetRHS(y1, rhs, t);
		for (int i = 0; i < numeqs; ++i) {
			k2[i] = dt * rhs[i];
			y2[i] = state[i] + 0.5 * k2[i];
		}

    RK4::GetRHS(y2, rhs, t);
		for (int i = 0; i < numeqs; ++i) {
			k3[i] = dt * rhs[i];
			y3[i] = state[i] + k3[i];
		}

    RK4::GetRHS(y3, rhs, t);
		for (int i = 0; i < numeqs; ++i) {
			k4[i] = dt * rhs[i];
		}

		for (int i = 0; i < numeqs; ++i) {
			state[i] = state[i] + (k1[i]+2.0*k2[i]+2.0*k3[i]+k4[i])/6.0;
		}
    t = t + dt;
  }
  delete [] k1; delete [] k2; delete [] k3; delete [] k4; 
  delete [] y1; delete [] y2; delete [] y3;
  k1 = nullptr; k2 = nullptr; k3 = nullptr; k4 = nullptr;
  y1 = nullptr; y2 = nullptr; y3 = nullptr;
}

int RK4::NumEqs(){
  // Number of equations in state
  return 6;
}

void RK4::GetRHS(double state[], double rhs[], double &t){
  // Get RHS term of Runge-Kutta Equations
  double x = state[0];
  double y = state[1];
  double z = state[2];
  double vx = state[3];
  double vy = state[4];
  double vz = state[5];
  double ax = -Constant::G *x/pow(x*x + y*y, 1.5);
  double ay = -Constant::G *y/pow(x*x + y*y, 1.5);
  double az = 0.0;
  // double ax = state[6];
  // double ay = state[7];
  // double az = state[8];

  std::cout << state[6] << " " << state[7] << " " << state[8] << std::endl;

  rhs[0] = vx;
  rhs[1] = vy;
  rhs[2] = vz;
  rhs[3] = ax;
  rhs[4] = ay;
  rhs[5] = az;
}
