#ifndef NAIVE_N_BODY_WINDOW
#define NAIVE_N_BODY_WINDOW

#include "SDL2/SDL.h"
#include "window/window.hpp"
#include "window/camera.hpp"
#include "element/square.hpp"
#include <iostream>

class NaiveNBodyWindow : public Window{
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