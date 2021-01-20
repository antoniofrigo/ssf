#ifndef FALLING_OBJECT_H
#define FALLING_OBJECT_H

#include "model/model.hpp"

class FallingObject : public Model {
  public:
    FallingObject(int id, int ndim);
    ~FallingObject();

    void EvaluateAt(double *output, double *state, double time);
}; 

#endif
