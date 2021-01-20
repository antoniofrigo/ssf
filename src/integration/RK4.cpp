#include "integration/RK4.hpp"

void RK4::SetInitial(double *state){
  i_state = state;
}

void RK4::ComputeStep(){
  
  // Compute k1
  i_model->EvaluateAt(i_k1, i_state, i_time);
  for (int i = 0; i < i_ndim; ++i) {
    i_temp[i] = i_state[i] + i_h * 0.5 * i_k1[i];
  }

  // Compute k2
  i_model->EvaluateAt(i_k2, i_temp, i_time);
  for (int i = 0; i < i_ndim; ++i) {
    i_temp[i] = i_state[i] + i_h * 0.5 * i_k2[i];
  }

  // Compute k3
  i_model->EvaluateAt(i_k3, i_temp, i_time);
  for (int i = 0; i < i_ndim; ++i) {
    i_temp[i] = i_state[i] + i_h * 0.5 * i_k3[i];
  }

  // Compute k4
  i_model->EvaluateAt(i_k4, i_temp, i_time);
  // Computes new state
  for (int i = 0; i < i_ndim; ++i) {
    i_state[i] += i_h * (i_k1[i] + 2.0e0 * (i_k2[i] + i_k3[i]) + i_k4[i]) / 6.0e0;
  }

  i_time += i_h;
}
