#ifndef SQUARE_H
#define SQUARE_H

#include <SDL2/SDL.h>

class Square{
  // Class for drawing squares in a window
 public:
  Square();
  ~Square();

  void Draw(int x, int y, int l, SDL_Renderer* render);
};

#endif