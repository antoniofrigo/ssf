#ifndef SQUARE_H
#define SQUARE_H

#include <SDL2/SDL.h>

class Square{
 public:
  Square();
  ~Square();

  void Draw(int x, int y, int l, SDL_Renderer* render);
};

#endif