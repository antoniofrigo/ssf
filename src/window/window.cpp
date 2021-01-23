#include "window/window.hpp"

#include <iostream>

Window::Window(int width, int height)
    : w_height(height), w_width(width), w_window(nullptr), w_open(false) {}

Window::~Window() {
  SDL_DestroyRenderer(w_render);
  SDL_DestroyWindow(w_window);
  SDL_Quit();
}

void Window::OpenWindow() {
  SDL_Init(SDL_INIT_VIDEO);
  w_window =
      SDL_CreateWindow(w_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       w_width, w_height, SDL_WINDOW_SHOWN);
  w_render = SDL_CreateRenderer(w_window, -1, SDL_RENDERER_ACCELERATED);

  w_open = true;

  while (w_open) {
    SDL_Event e;
    // Main input loop
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        w_open = false;
        break;
      }
      Window::HandleInput(&e);
    }

    Window::DrawScene();
  }
}

void Window::SetWindowTitle(char* title) { w_title = title; }

void Window::HandleInput(SDL_Event* e) {
  // Handles keyboard inputs
  switch (e->type) {
    case SDL_KEYDOWN:
      switch (e->key.keysym.sym) {
        case (SDLK_q):
          w_open = false;
      }
  }
}

void Window::DrawScene() {
  // Draws test rectangle
  SDL_RenderClear(w_render);
  SDL_Rect rect;
  rect.x = 250;
  rect.y = 150;
  rect.w = 200;
  rect.h = 200;

  SDL_SetRenderDrawColor(w_render, 0, 255, 255, 255);
  SDL_RenderFillRect(w_render, &rect);
  SDL_SetRenderDrawColor(w_render, 0, 0, 0, 255);
  SDL_RenderPresent(w_render);
}