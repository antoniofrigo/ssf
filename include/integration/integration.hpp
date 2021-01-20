#ifndef INTEGRATION_H
#define INTEGRATION_H

#include "model/model.hpp"

class Integration {
  // Base class for integration methods
  public:
    Integration(Model *i_model, int i_dim);
    
    void SetStep(double h);
    double GetStepSize() const;

    virtual ~Integration();
    virtual void SetInitial(double *state) = 0;

  protected:
    Model *i_model;
    int i_ndim; 
    double i_h;
    double i_time;
};

#endif
