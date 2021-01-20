#ifndef INTEGRATION_RK4
#define INTEGRATION_RK4

#include "integration/integration.hpp"

class RK4 : public Integration{
  public:
    ~RK4();
    void SetInitial(double *state);
    void ComputeStep();

    // Will inherit:
    //    Integration(Model *i_model, int i_dim);
    //    void SetStep(double h);
    //    double GetStep() const;
    //    void Evaluate();

  private:
    double *i_state;
    double *i_k1;
    double *i_k2;
    double *i_k3;
    double *i_k4;
    double *i_temp;
    // Will inherit:
    //    Model *i_model;
    //    int i_ndim; 
    //    double i_h;
};

#endif
