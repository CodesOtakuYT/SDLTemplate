#include "SDL.h"
#include "Window.h"

int main() {
    auto result = Window::init();
    if (!result) {
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, result.error());
        return 1;
    }

    try {
        Window window("CODOTAKU");
        bool isRunning = true;

        while (isRunning) {
            std::optional<SDL_Event> event;
            while ((event = Window::pollEvent()))
                switch (event->type) {
                    case SDL_EventType::SDL_EVENT_QUIT:
                        isRunning = false;
                        break;
                }

            // RENDER
        }
    } catch (std::exception &exception) {
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, exception.what());
        return 1;
    }

    Window::quit();
    return 0;
}