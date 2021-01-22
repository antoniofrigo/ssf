#ifndef SINGLE_PARTICLE_H
#define SINGLE_PARTICLE_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "element/element.hpp"
#include <string>

class Square : public Element {
  public:
    Square(SDL_Window * window);
    ~Square();

    template <class T> void DrawElement(T& x, T& y, T& z);
    void Unload() override;
  private:
    GLuint vao;
    GLuint ebo;
    GLuint vbo;
    GLuint shaderProgram;
    GLuint fragmentShader;
    GLuint vertexShader;

};

#endif
