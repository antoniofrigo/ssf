#include "integration/integration.hpp"


Integration::Integration(Model *_i_model, int _i_ndim){
  this->i_model = _i_model;
  this->i_ndim = _i_ndim;
}

Integration::~Integration(){}

void Integration::SetStep(double h){
  i_h = h;
}

double Integration::GetStepSize() const {
  return i_h;
}
