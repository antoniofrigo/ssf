#ifndef FALLING_OBJECT_H
#define FALLING_OBJECT_H

#include "model/model.hpp"

class FallingObject : public Model {
  public:
    ~FallingObject();

    void EvaluateAt(double *output, double *state, double time);
    void SetInitialState(double *state);
  private:
    double *m_state;
}; 

#endif
