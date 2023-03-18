#include "Window.h"
#include "SDL.h"

#include <stdexcept>

Window::Window(const std::string &title, int width, int height, unsigned int flags) : m_window(nullptr,
                                                                                               SDL_DestroyWindow) {
    // SDL_InitSubSystem is ref-counted
    SDL_InitSubSystem(SDL_InitFlags::SDL_INIT_VIDEO);
    auto window = SDL_CreateWindow(title.c_str(), width, height, flags);
    if (window) {
        m_window.reset(window);
    } else {
        throw std::runtime_error(SDL_GetError());
    }
}

Window::~Window() {
    // SDL_QuitSubSystem is ref-counted
    SDL_QuitSubSystem(SDL_InitFlags::SDL_INIT_VIDEO);
}

std::optional<SDL_Event> Window::pollEvent() {
    SDL_Event event;
    if (SDL_PollEvent(&event))
        return event;
    else
        return {};
}