#include "window/window.hpp"

Window::Window()
    : w_frame(0),
      w_open(false),
      w_set_dim(false),
      w_set_fps(false),
      w_set_state(false),
      w_set_iterations(false) {}

Window::~Window() {
  SDL_DestroyRenderer(w_render);
  SDL_DestroyWindow(w_window);
  SDL_Quit();
}

void Window::CheckInit() const {
  // Checks whether all necessary quantities are initialized properly.
  if (!(w_set_dim && w_set_fps && w_set_state && w_set_iterations)) {
    throw std::runtime_error(
        "Window attributes undefined. Attributes: w_set_dim, w_set_fps, "
        "w_set_state, w_set_iterations");
  }
}

void Window::SetWindowDimension(int width, int height) {
  // Set dimensions of rendering window
  w_width = width;
  w_height = height;
  w_set_dim = true;
}

void Window::SetWindowFPS(int fps) {
  // Set FPS of rendering
  w_set_fps = true;
  w_fps = fps;
}

void Window::SetState(double** new_state) {
  // Set state from which output is rendered
  w_set_state = true;
  state = new_state;
}

void Window::SetWindowIterations(int iterations) {
  // Set number of iterations that are shown,
  // essentially the number of times DrawScene is called
  w_set_iterations = true;
  w_iterations = iterations;
}

void Window::SetWindowTitle(char* title) { w_title = title; }

int Window::GetWindowWidth() const { return w_width; }

int Window::GetWindowHeight() const { return w_height; }

int Window::GetWindowFPS() const { return w_fps; }

int Window::GetWindowIterations() const { return w_iterations; }

void Window::CreateWindow() {
  // Creates window
  CheckInit();
  SDL_Init(SDL_INIT_VIDEO);
  w_window =
      SDL_CreateWindow("HERE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       w_width, w_height, SDL_WINDOW_SHOWN);
  w_render = SDL_CreateRenderer(w_window, -1, SDL_RENDERER_ACCELERATED);
  w_open = true;
  MainLoop();
}

void Window::MainLoop() {
  double start;
  double end;
  double delay_time;
  double frame_time = 1000.0 / w_fps;

  while (w_open) {
    start = SDL_GetTicks();
    SDL_Event e;
    // Handle Input Loops
    while (SDL_PollEvent(&e)) {
      HandleQuit(&e);
      HandleInput(&e);
    }
    // Draw frame w_frame
    DrawScene(w_frame);
    w_frame++;

    // Delays rendering to cap FPS
    end = SDL_GetTicks();
    delay_time = std::max(frame_time - (end - start), 0.0e0);
    SDL_Delay(delay_time);

    if (w_frame >= w_iterations) {
      return;
    }
  }
}

void Window::HandleQuit(SDL_Event* e) {
  // Handles quit events
  if (e->type == SDL_QUIT) {
    w_open = false;
  } else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_q) {
    w_open = false;
  }
}

void Window::HandleInput(SDL_Event* e) { (void)e; }

void Window::DrawScene(int frame) { (void)frame; }