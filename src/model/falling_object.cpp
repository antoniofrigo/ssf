#include "model/model.hpp"
#include "model/falling_object.hpp"

FallingObject::FallingObject(int id, int ndim) : 
  Model(id, ndim){}

FallingObject::~FallingObject(){}

void FallingObject::EvaluateAt(double *output, double *state, double time){
  output[0] = state[2];
  output[1] = state[3];
  output[2] = 0.0e0;
  output[3] = -9.8e0;
}

