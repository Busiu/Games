//
// Created by Busiu on 14.09.2018.
//

#ifndef GAMES_RENDERER_HPP
#define GAMES_RENDERER_HPP

#include "../Libraries.hpp"
#include "../Exception.hpp"

#include "Renderable.hpp"

#include "../util/Position.hpp"

class Renderable;

class Renderer {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Renderer(Position<int>* windowSize);
    ~Renderer();

    void clear();
    void update();

    SDL_Renderer* getRenderer();

    void setResolution(Position<int>* resolution);

    void render(Renderable* renderable);

private:
    //Constructor
    bool initWindow(Position<int>* windowSize);
    bool initRenderer();

    //Destructor
    void destroyWindow();
    void destroyRenderer();
};


#endif //GAMES_RENDERER_HPP
