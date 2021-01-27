#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL_ttf.h>

#include <cmath>
#include <iostream>
#include <stdexcept>

#include "SDL2/SDL.h"

class Window {
  // Base class to draw window
 public:
  Window();
  ~Window();

  void SetWindowDimension(int width, int height);
  int GetWindowWidth() const;
  int GetWindowHeight() const;
  void SetWindowFPS(int fps);
  int GetWindowFPS() const;
  void SetWindowIterations(int fps);
  int GetWindowIterations() const;

  void CheckInit() const;

  void CreateWindow();
  void HandleQuit(SDL_Event* e);
  void SetState(double** new_state);
  void MainLoop();

  void SetWindowTitle(char* title);
  virtual void HandleInput(SDL_Event* e);
  virtual void DrawScene(int frame);

  void DisplayText(const char* msg, int x, int y);

 protected:
  int w_width;
  int w_height;
  int w_fps;
  int w_frame;
  int w_iterations;
  char* w_title;

  bool w_open;
  bool w_set_dim;
  bool w_set_fps;
  bool w_set_state;
  bool w_set_iterations;

  double** state;

  SDL_Window* w_window;
  SDL_Renderer* w_render;
  TTF_Font* font;
};

#endif