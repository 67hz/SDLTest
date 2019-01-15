#include <iostream>
#include <SDL.h>
using namespace std;

int main() {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL Init failed" << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
            "Particle Fire Explosion",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN );

    if(window == NULL) {
        cout << "Could not create window: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(
            renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
            SCREEN_WIDTH, SCREEN_HEIGHT);

    if(renderer == NULL) {
        cout << "Could not create renderer" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }

    if(texture == NULL) {
        cout << "Could not create texture" << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }

    // Uint32 is SDL type @ 32 bits
    // each pixel is r,g,b,a -> 4 * 8 bits - 32 bits
    Uint32 *buffer = new Uint32(SCREEN_WIDTH * SCREEN_HEIGHT);

    // memset - set block of memory with particular value
//    memset(buffer, 255, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    bool quit = false;

    SDL_Event event;

    // Game Loop
    while(!quit) {
        // update particles
        // draw particles
        // check for messages(events)

        while(SDL_PollEvent(&event)) {

            if(event.type == SDL_QUIT) {
                quit = true;
            }

        }


    }

    // buffer is array so [] necessary
    delete [] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}