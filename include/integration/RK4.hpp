#ifndef INTEGRATION_RK4
#define INTEGRATION_RK4

#include "integration/integration.hpp"
#include "model/model.hpp"

class RK4 : public Integration {
  // Fourth order Runge-Kutta integrator
 public:
  RK4(Model *i_model, int i_dim);
  ~RK4();

  void ComputeStep(double *state_old, double *state_new);

 private:
  double *i_k1;
  double *i_k2;
  double *i_k3;
  double *i_k4;
  double *i_temp;
};

#endif
