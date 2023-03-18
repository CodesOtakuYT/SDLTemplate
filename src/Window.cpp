#include "Window.h"
#include "stdexcept"

Window::Window(const std::string &title, int width, int height, SDL_WindowFlags flags)
        : m_window(SDL_CreateWindow(title.c_str(), width, height, flags), &SDL_DestroyWindow) {
    if (!m_window)
        throw std::runtime_error(SDL_GetError());
}

std::expected<void, const char *> Window::init() {
    if (SDL_InitSubSystem(SDL_InitFlags::SDL_INIT_VIDEO))
        return std::unexpected(SDL_GetError());
    return {};
}

void Window::quit() {
    SDL_QuitSubSystem(SDL_InitFlags::SDL_INIT_VIDEO);
}

std::optional<SDL_Event> Window::pollEvent() {
    SDL_Event event;
    if (SDL_PollEvent(&event))
        return event;
    else
        return std::nullopt;
}