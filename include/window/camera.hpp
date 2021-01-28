#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>
#include <iostream>

class Camera {
 public:
  Camera();
  ~Camera();

  int GetPhi() const;      // Returns phi
  int GetTheta() const;    // Returns theta
  int GetR() const;        // Returns r
  double GetZoom() const;  // Returns zoom

  void IncrementPhi();    // Increase phi
  void IncrementTheta();  // Increase theta
  void IncrementR();      // Increase r
  void IncrementZoom();   // Increase zoom

  void DecrementPhi();    // Decrease phi
  void DecrementTheta();  // Decrease theta
  void DecrementR();      // Decrease r
  void DecrementZoom();   // Decrease zoom

  void Transform(int &x, int &y, int &z);  // Transform coordinates to camera
  void UpdateLocation();                   // Update location of camera
  void PrintLocationCartesian() const;
  void PrintLocationSpherical() const;

 private:
  // Spherical coordinates
  int phi;
  int theta;
  int r;

  // Coordinates for camera transform
  double pitch;
  double roll;
  double yaw;

  // Zoom multiplier
  double zoom;

  // Camera location in Cartesian
  double cx;
  double cy;
  double cz;
};

#endif