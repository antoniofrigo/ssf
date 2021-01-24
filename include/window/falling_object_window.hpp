#ifndef FALLING_OBJECT_WINDOW
#define FALLING_OBJECT_WINDOW

#include "SDL2/SDL.h"
#include "window/window.hpp"
#include "element/square.hpp"
#include <iostream>

class FallingObjectWindow : public Window{
  public:
    FallingObjectWindow();
    ~FallingObjectWindow();

    void DrawScene(int frame) override;
    void DrawSquare(int x, int y, int l);
};
#endif