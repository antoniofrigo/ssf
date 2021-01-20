#ifndef MODEL_H
#define MODEL_H

class Model {
  public:
    Model(const int m_id, const int m_ndim); 
    virtual ~Model();

    void SetDim(double ndim);
    int GetDim() const;

    virtual void EvaluateAt(double *output, double *state, double time) = 0;
    virtual void SetInitialState(double *state) = 0;

  private:
    int m_ndim;
    int m_id; 
};

#endif
