#ifndef SQUARE_H
#define SQUARE_H

#include <SDL2/SDL.h>

#include "element/element.hpp"

class Square : public Element {
 public:
  Square(SDL_Renderer* render);
  ~Square();

  void Draw(int x, int y, int l);
};

#endif