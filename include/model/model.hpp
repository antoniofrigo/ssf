#ifndef MODEL_H
#define MODEL_H

class Model {
 public:
  Model(int m_id, int m_ndim);
  virtual ~Model();

  void SetDim(double ndim);
  int GetDim() const;
  void SetInitial(double *state);

  virtual void EvaluateAt(double *output, double *state, double time) = 0;

 protected:
  int m_ndim;
  int m_id;
  double *m_initial;
};

#endif
