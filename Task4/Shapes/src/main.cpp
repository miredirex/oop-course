#include <fstream>
#include "SDL.h"
#include "canvas/SDLCanvas.h"
#include "Point.h"
#include "Scene.h"
#include "calculation/Calculations.h"

void PrintHelp()
{
    std::cout << "Draw commands:\n"
              << "line x1 y1 x2 y2 line_color" << '\n'
              << "rectangle x1 y1 x2 y2 outline_color fill_color" << '\n'
              << "circle center_x1 center_y1 radius outline_color fill_color" << '\n'
              << "triangle x1 y1 x2 y2 x3 y3 outline_color fill_color" << '\n'
              << "\nExample: circle 250.0 250.0 100 bbe4ff effc0e\n";
}

SDL_Window* SDLSetupWindow()
{
    SDL_Window* window = SDL_CreateWindow("Shapes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,
                                          SDL_WINDOW_SHOWN);

    // Setup renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RendererFlags::SDL_RENDERER_SOFTWARE);

    // Set render color to white ( background will be rendered in this color )
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Clear window
    SDL_RenderClear(renderer);

    return window;
}

int main(int argc, char* argv[])
{
    SDL_Window* window = SDLSetupWindow();
    SDL_Renderer* renderer = SDL_GetRenderer(window);

    SDLCanvas canvas(renderer);

    PrintHelp();

    Scene scene;
    // Enter draw mode
    scene.InputDrawMode(std::cin);
    scene.DrawScene(canvas);

    std::cout << "Shape with largest area: \n";
    std::cout << FindWithLargestArea(scene.GetShapes())->ToString() << '\n';
    std::cout << "Shape with least perimeter: \n";
    std::cout << FindWithLeastPerimeter(scene.GetShapes())->ToString() << '\n';
    std::cout << std::endl;

    // SDL Loop
    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                SDL_DestroyWindow(window);
                SDL_Quit();
                quit = true;
            }
        }
    }

    return 0;
}