#pragma once

#include <memory>
#include <string>
#include <expected>
#include <optional>

// SDL Forward Declarations
typedef struct SDL_Window SDL_Window;

extern "C" void SDL_DestroyWindow(SDL_Window *);

typedef union SDL_Event SDL_Event;

class Window {
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
public:
    explicit Window(const std::string &title, int width = 800, int height = 600,
                    unsigned int flags = 0);

    static std::expected<void, const char *> init();

    static void quit();

    static std::optional<SDL_Event> pollEvent();
};