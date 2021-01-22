#ifndef ELEMENT_H
#define ELEMENT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SDL2/SDL.h>

class Element {
  public:
    Element(SDL_Window * window);
    ~Element();

    virtual void DrawElement();
    virtual void Unload();
  protected:
    SDL_Window * e_window;
};

#endif
