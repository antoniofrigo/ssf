#include "integration/integration.hpp"

#include <iostream>

Integration::Integration(Model *model, int ndim):
  i_model(model), i_ndim(ndim), i_h(1){}

Integration::~Integration(){}

void Integration::SetStepSize(double h){
  i_h = h;
}

double Integration::GetStepSize() const {
  return i_h;
}

void Integration::SetInitial(double *state){
  i_state = state;
}

void Integration::PrintState() const {
  for (int i = 0; i < i_ndim; ++i) {
    std::cout << i_state[i] << " ";
  }
  std::cout << std::endl;
}
