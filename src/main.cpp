#include "Window.h"
#include "SDL.h"

void handleInput(bool &shouldQuit) {
    std::optional<SDL_Event> event;
    while ((event = Window::pollEvent()))
        switch (event->type) {
            case SDL_EventType::SDL_EVENT_QUIT:
                shouldQuit = true;
                break;
        }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    try {
        // Application Start
        Window window("CODOTAKU");

        // Application Loop
        bool shouldQuit = false;
        while (!shouldQuit) {
            handleInput(shouldQuit);
            // Update
            // Render
        }
    } catch (const std::exception &exception) {
        auto errorMessage = exception.what();
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, "%s", errorMessage);
        SDL_ShowSimpleMessageBox(SDL_MessageBoxFlags::SDL_MESSAGEBOX_ERROR, "Error Message", errorMessage, nullptr);
        SDL_Quit();
        return 1;
    }

    // Must be called even if all subsystems are shut down
    SDL_Quit();
    return 0;
}