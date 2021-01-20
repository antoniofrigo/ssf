#ifndef INTEGRATION_H
#define INTEGRATION_H

#include "model/model.hpp"

class Integration {
  // Base class for integration methods
  public:
    Integration(Model *i_model, int i_dim);
    
    void SetStepSize(double h);
    double GetStepSize() const;
    void PrintState() const;

    virtual ~Integration();
    virtual void SetInitial(double *state);

  protected:
    Model *i_model;
    double *i_state;
    int i_ndim; 
    double i_h;
    double i_time;
};

#endif
