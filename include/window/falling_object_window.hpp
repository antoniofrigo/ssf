#ifndef FALLING_OBJECT_WINDOW
#define FALLING_OBJECT_WINDOW

#include <iostream>

#include "SDL2/SDL.h"
#include "element/square.hpp"
#include "window/window.hpp"

class FallingObjectWindow : public Window {
  // Window for drawing falling object
 public:
  FallingObjectWindow();
  ~FallingObjectWindow();

  void DrawScene(int frame) override;
  void DrawSquare(int x, int y, int l);
};
#endif