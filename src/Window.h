#pragma once

#include <memory>
#include <string>
#include <optional>

// SDL Forward Declarations
struct SDL_Window;

union SDL_Event;

using SDL_Window_deleter = void (*)(SDL_Window *);

class Window {
    std::unique_ptr<SDL_Window, SDL_Window_deleter> m_window;
public:
    explicit Window(const std::string &title, int width = 800, int height = 600,
                    unsigned int flags = 0);

    ~Window();

    static std::optional<SDL_Event> pollEvent();
};