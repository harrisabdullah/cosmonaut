#include <SDL2/SDL.h>

int main() {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(700, 700, 0, &window, &renderer);

    bool run = true;

    while (run) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT){
                run = false;
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(30);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
