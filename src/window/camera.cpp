#include "window/camera.hpp"

Camera::Camera()
    : phi(0),
      theta(0),
      r(10000),
      pitch(theta * 0.01745),
      roll(0),
      yaw(phi * 0.01745),
      zoom(1),
      cx(r * sin(theta * 0.01745) * cos(phi * 0.01745)),
      cy(r * sin(theta * 0.01745) * sin(phi * 0.01745)),
      cz(r * cos(theta * 0.01745)) {}

Camera::~Camera() {}

void Camera::UpdateLocation() {
  pitch = theta * 0.01745;
  roll = 0.0;
  yaw = phi * 0.01745;
  cx = r * sin(theta * 0.01745) * cos(phi * 0.01745);
  cy = r * sin(theta * 0.01745) * sin(phi * 0.01745);
  cz = r * cos(theta * 0.01745);
}

void Camera::IncrementPhi() {
  phi += 2;
  phi %= 360;
  UpdateLocation();
}

void Camera::IncrementTheta() {
  theta += 2;
  theta %= 360;
  UpdateLocation();
}

void Camera::IncrementR() {
  r += 10;
  UpdateLocation();
}

void Camera::IncrementZoom() {
  zoom += 0.05;
  UpdateLocation();
}

void Camera::DecrementPhi() {
  phi += 358;
  phi %= 360;
  UpdateLocation();
}

void Camera::DecrementTheta() {
  theta += 358;
  theta %= 360;
  UpdateLocation();
}

void Camera::DecrementR() {
  if (r > 20) {
    r -= 10;
  }
  UpdateLocation();
}

void Camera::DecrementZoom() {
  if (zoom > 0.10) {
    zoom -= 0.05;
  }
  UpdateLocation();
}

void Camera::Transform(int &x, int &y, int &z) {
  double lx = x - cx;
  double ly = y - cy;
  double lz = z - cz;

  x = cos(pitch) * (sin(yaw) * ly + cos(yaw) * lx) - sin(pitch) * lz;
  y = cos(yaw) * ly - sin(yaw) * lx;
  z = cos(pitch) * lz + sin(pitch) * (sin(yaw) * ly + cos(yaw) * lx);
  x = x / zoom;
  y = y / zoom;
  z = z / zoom;
}

void Camera::PrintLocationCartesian() const {
  std::cout << "x: " << cx << " ";
  std::cout << "y: " << cy << " ";
  std::cout << "z: " << cz << std::endl;
}

void Camera::PrintLocationSpherical() const {
  std::cout << "Zoom: " << zoom << " ";
  std::cout << "Phi: " << phi << " ";
  std::cout << "Theta: " << theta << " ";
  std::cout << "R: " << r << std::endl;
}

int Camera::GetPhi() const { return phi; }

int Camera::GetTheta() const { return theta; }

int Camera::GetR() const { return r; }

double Camera::GetZoom() const { return zoom; }