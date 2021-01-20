#ifndef INTEGRATION_H
#define INTEGRATION_H

class Integration {
  // Base class for integration methods
  public:
    void Init();
    void SetTimestep();

  protected:
    void Evaluate();

}

#endif
