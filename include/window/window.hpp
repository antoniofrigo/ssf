#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

#include "SDL2/SDL.h"

class Window {
  // Base class to draw window
 public:
  Window(int width, int height);
  ~Window();

  void OpenWindow();
  void SetWindowTitle(char* title);
  virtual void HandleInput(SDL_Event* e);
  virtual void DrawScene();

 protected:
  int w_width;
  int w_height;
  bool w_open;
  char* w_title;

  SDL_Window* w_window;
  SDL_Renderer* w_render;
};

#endif