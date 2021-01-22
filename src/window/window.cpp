#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <iostream>
#include "window/window.hpp"

Window::Window(int width, int height, std::string title) :
  w_width(width),
  w_height(height),
  w_title(title),
  w_open(true){
  }

Window::~Window(){
  SDL_GL_DeleteContext(w_context);
  SDL_Quit();
}

void Window::GetWindow(SDL_Window * window) const {
  window = w_window;
}

void Window::CreateWindow(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    w_window = SDL_CreateWindow("testing", 0, 0, w_width, w_height, SDL_WINDOW_OPENGL);
}

void Window::WindowLoop() {
  w_context = SDL_GL_CreateContext(w_window);
  glewExperimental = GL_TRUE;
  glewInit();
  SDL_Event windowEvent;
  while (true)
  {
    if (windowEvent.type == SDL_QUIT) {break;}
    if (SDL_PollEvent(&windowEvent)){
      if (windowEvent.key.keysym.sym == SDLK_ESCAPE) break;
    }
    SDL_GL_SwapWindow(w_window); 
    this->UpdateScene();
    this->DrawGraphics();
    this->PresentGraphics();
  }
  this->Unload();
}

void Window::HandleEvent(SDL_Event &windowEvent){}

void Window::UpdateScene() {}

void Window::DrawGraphics() {}

void Window::PresentGraphics() {}

void Window::Unload() {}

