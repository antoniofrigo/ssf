#include "element/square.hpp"

Square::Square() {}

Square::~Square() {}

void Square::Draw(int x, int y, int l, SDL_Renderer* render) {
  // Draw square of side length l centered at x, y
  SDL_Rect rect;
  rect.x = x - l/2;
  rect.y = y - l/2;
  rect.w = l;
  rect.h = l;

  SDL_SetRenderDrawColor(render, 0, 255, 255, 255);
  SDL_RenderFillRect(render, &rect);
  SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
  SDL_RenderPresent(render);
}
