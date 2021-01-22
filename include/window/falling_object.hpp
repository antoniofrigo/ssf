#ifndef FALLING_OBJECT_WINDOW_H
#define FALLING_OBJECT_WINDOW_H

#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <string>

class FallingObjectWindow {
  public:
    FallingObjectWindow(int width, int height, std::string title);
    ~FallingObjectWindow();
    virtual void WindowLoop();

    virtual void HandleEvent(SDL_Event &windowEvent);
    virtual void UpdateScene();
    virtual void DrawGraphics();
    virtual void PresentGraphics();
    virtual void Unload();
};
#endif
