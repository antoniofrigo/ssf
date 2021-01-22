#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <string>

class Window {
  public:
    Window(int width, int height, std::string title);
    ~Window();
    void CreateWindow();
    void CreateOpenGLContext();
    void GetWindow(SDL_Window * window) const;
    virtual void WindowLoop();

    virtual void HandleEvent(SDL_Event &windowEvent);
    virtual void UpdateScene();
    virtual void DrawGraphics();
    virtual void PresentGraphics();
    virtual void Unload();

  protected:
    int w_width;
    int w_height;
    std::string w_title;

    bool w_open;
    SDL_GLContext w_context;
    SDL_Window * w_window;
};
#endif
