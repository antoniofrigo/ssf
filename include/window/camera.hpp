#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>
#include <iostream>

class Camera {
 public:
  Camera();
  ~Camera();

  void IncrementPhi();
  void IncrementTheta();
  void IncrementR();
  void IncrementZoom();

  void DecrementPhi();
  void DecrementTheta();
  void DecrementR();
  void DecrementZoom();

  void Transform(int &x, int &y, int &z);
  void UpdateLocation();
  void PrintLocationCartesian() const;
  void PrintLocationSpherical() const;

 private:
  int phi;
  int theta;
  int r;

  double pitch;
  double roll;
  double yaw;

  double zoom;
  double cx;
  double cy;
  double cz;

};

#endif