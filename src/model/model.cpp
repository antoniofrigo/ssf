#include "model/model.hpp"

Model::Model(const int id, const int ndim){
  this->m_id = id;
  this->m_ndim = ndim;
}

Model::~Model(){}

void Model::SetInitialState(double *state){}

void Model::SetDim(double ndim){
  this->m_ndim = ndim;
}

void Mode::GetDim() const {
  return m_ndim;
}
