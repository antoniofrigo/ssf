#include "model/model.hpp"

Model::Model(int id, int ndim) : m_ndim(ndim), m_id(id) {}

Model::~Model() {}

void Model::SetInitial(double *state) { m_initial = state; }

void Model::SetDim(double ndim) { m_ndim = ndim; }

int Model::GetDim() const { return m_ndim; }
