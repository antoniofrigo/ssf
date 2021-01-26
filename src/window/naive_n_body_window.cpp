#include "window/naive_n_body_window.hpp"

NaiveNBodyWindow::NaiveNBodyWindow() : Window(), Cam() {}

NaiveNBodyWindow::~NaiveNBodyWindow() {}

void NaiveNBodyWindow::SetBodies(int num) { m_bodies = num; }

void NaiveNBodyWindow::DrawScene(int frame) {
  SDL_RenderClear(w_render);

  DrawAxisLines();
  int x, y, z;
  for (int i = 0; i < m_bodies; ++i) {
    x = state[frame][3 * i + 0] / 1e9;
    y = state[frame][3 * i + 1] / 1e9;
    z = state[frame][3 * i + 2] / 1e9;
    Cam.Transform(x, y, z);
    DrawSquare(w_width / 2 + x, w_height / 2 + y, 10);
  }
  SDL_SetRenderDrawColor(w_render, 0, 0, 0, 255);
  SDL_RenderPresent(w_render);
}

void NaiveNBodyWindow::DrawSquare(int x, int y, int l) {
  // Draw square of side length l centered at x, y
  SDL_Rect rect;
  rect.x = x - l / 2;
  rect.y = y - l / 2;
  rect.w = l;
  rect.h = l;

  SDL_SetRenderDrawColor(w_render, 255, 255, 255, 255);
  SDL_RenderFillRect(w_render, &rect);
}

void NaiveNBodyWindow::DrawAxisLines() {
  // Draw x-axis
  int x1 = -w_width / 2, y1 = 0, z1 = 0, x2 = w_width / 2, y2 = 0, z2 = 0;
  Cam.Transform(x1, y1, z1);
  Cam.Transform(x2, y2, z2);

  SDL_SetRenderDrawColor(w_render, 0, 120, 255, 30);
  SDL_RenderDrawLine(w_render, w_width / 2 + 0, w_height / 2 + 0,
                     w_width / 2 + x2, w_height / 2 + y2);

  // Draw y-axis
  x1 = 0, y1 = -w_height / 2, z1 = 0, x2 = 0, y2 = w_height / 2, z2 = 0;
  Cam.Transform(x1, y1, z1);
  Cam.Transform(x2, y2, z2);

  SDL_SetRenderDrawColor(w_render, 120, 0, 255, 30);
  SDL_RenderDrawLine(w_render, w_width / 2 + 0, w_height / 2 + 0,
                     w_width / 2 + x2, w_height / 2 + y2);

  // Draw z-axis
  x1 = 0, y1 = 0, z1 = -w_height / 2, x2 = 0, y2 = 0, z2 = w_height / 2;
  Cam.Transform(x1, y1, z1);
  Cam.Transform(x2, y2, z2);

  SDL_SetRenderDrawColor(w_render, 0, 255, 120, 30);
  SDL_RenderDrawLine(w_render, w_width / 2 + 0, w_height / 2 + 0,
                     w_width / 2 + x2, w_height / 2 + y2);
}

void NaiveNBodyWindow::HandleInput(SDL_Event* e) {
  // Handles input to control camera
  switch (e->type) {
    case (SDL_KEYDOWN):
      switch (e->key.keysym.sym) {
        case (SDLK_UP):
          Cam.IncrementTheta();
          Cam.PrintLocationSpherical();
          break;
        case (SDLK_DOWN):
          Cam.DecrementTheta();
          Cam.PrintLocationSpherical();
          break;
        case (SDLK_RIGHT):
          Cam.IncrementPhi();
          Cam.PrintLocationSpherical();
          break;
        case (SDLK_LEFT):
          Cam.DecrementPhi();
          Cam.PrintLocationSpherical();
          break;
        case (SDLK_x):
          Cam.IncrementZoom();
          Cam.PrintLocationSpherical();
          break;
        case (SDLK_z):
          Cam.DecrementZoom();
          Cam.PrintLocationSpherical();
          break;
        default:
          break;
      }
  }
}