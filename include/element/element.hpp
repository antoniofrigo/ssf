#ifndef ELEMENT_H
#define ELEMENT_H

#include <SDL2/SDL.h>

class Element {
  // Base class for drawn element in window
 public:
  Element(SDL_Renderer* render);
  ~Element();

  virtual void Draw();

 protected:
  SDL_Renderer* e_render;
};

#endif