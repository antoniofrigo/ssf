#ifndef NAIVE_N_BODY_WINDOW
#define NAIVE_N_BODY_WINDOW

#include <iostream>
#include <string>

#include "SDL2/SDL.h"
#include "element/square.hpp"
#include "window/camera.hpp"
#include "window/window.hpp"

class NaiveNBodyWindow : public Window {
 public:
  NaiveNBodyWindow();
  ~NaiveNBodyWindow();

  void SetBodies(int num);

  void DrawScene(int frame) override;
  void DrawSquare(int x, int y, int l);
  void DrawAxisLines();
  void HandleInput(SDL_Event* e) override;

 private:
  int m_bodies;
  Camera Cam;
};
#endif