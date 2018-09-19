//
// Created by Busiu on 14.09.2018.
//

#ifndef GAMES_RENDERER_HPP
#define GAMES_RENDERER_HPP

#include "../Libraries.hpp"
#include "../Exception.hpp"

#include "Renderable.hpp"

#include "../util/Pair.hpp"

class Pair;
class Renderable;

class Renderer {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Renderer(int WINDOW_WIDTH, int WINDOW_HEIGHT);
    ~Renderer();

    void clear();
    void update();

    SDL_Renderer* getRenderer();

    void setResolution(Pair* resolution);

    void render(Renderable* renderable);

private:
    //Constructor
    bool initWindow(int WINDOW_WIDTH, int WINDOW_HEIGHT);
    bool initRenderer();

    //Destructor
    void destroyWindow();
    void destroyRenderer();
};


#endif //GAMES_RENDERER_HPP
