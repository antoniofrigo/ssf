#include "window/falling_object_window.hpp"

FallingObjectWindow::FallingObjectWindow()
    : Window() {}

FallingObjectWindow::~FallingObjectWindow() {}

void FallingObjectWindow::DrawScene(int frame) {
  SDL_RenderClear(w_render);

  int x = w_width / 2 + state[frame][0];
  int y = w_height / 2 - state[frame][1];

  DrawSquare(x, y, 4);
}

void FallingObjectWindow::DrawSquare(int x, int y, int l) {
  // Draw square of side length l centered at x, y
  SDL_Rect rect;
  rect.x = x - l / 2;
  rect.y = y - l / 2;
  rect.w = l;
  rect.h = l;

  SDL_SetRenderDrawColor(w_render, 0, 255, 255, 255);
  SDL_RenderFillRect(w_render, &rect);
  SDL_SetRenderDrawColor(w_render, 0, 0, 0, 255);
  SDL_RenderPresent(w_render);
}