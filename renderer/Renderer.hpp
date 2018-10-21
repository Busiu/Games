//
// Created by Busiu on 14.09.2018.
//

#ifndef GAMES_RENDERER_HPP
#define GAMES_RENDERER_HPP

#include "../Libraries.hpp"
#include "../Exception.hpp"

#include "Renderable.hpp"

#include "../util/Types.hpp"

class Renderable;

class Renderer {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    explicit Renderer(Resolution windowSize);
    ~Renderer();

    void clear();
    void update();

    SDL_Renderer* getRenderer();

    void setResolution(Resolution resolution);

    void render(Renderable* renderable);

private:
    //Constructor
    bool initWindow(Resolution windowSize);
    bool initRenderer();

    //Destructor
    void destroyWindow();
    void destroyRenderer();
};


#endif //GAMES_RENDERER_HPP
