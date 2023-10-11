#include <SDL2/SDL.h>
#include "PhysicsObj.h"

int main() {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(700, 700, 0, &window, &renderer);

    PhysicsObj obj1 = {.position={.x=50, .y=130}, .velocity={.x=10, .y=0}, .radius=30, .mass=20e12, .timeInterval=0.033};
    PhysicsObj obj2 = {.position={.x=150, .y=150}, .velocity={.x=0, .y=0}, .radius=30, .mass=20e12, .timeInterval=0.033};


    bool run = true;
    while (run) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT){
                run = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // obj1.applyGravity(&obj2);
        obj1.applyElasticCollision(&obj2);
        obj1.updatePos();
        obj2.updatePos();

        SDL_RenderDrawPoint(renderer, obj1.position.x, obj1.position.y);
        SDL_RenderDrawPoint(renderer, obj2.position.x, obj2.position.y);

        SDL_RenderPresent(renderer);
        SDL_Delay(30);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
