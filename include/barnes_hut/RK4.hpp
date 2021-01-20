#ifndef RK4_H
#define RK4_H

#include "barnes_hut/Body.hpp"

namespace RK4 {
  void RK4Solver(double *state, double &dt, double &tstop);
  int NumEqs();
  void GetRHS(double *state, double *rhs, double &t);
}

#endif
