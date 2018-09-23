//
// Created by Busiu on 18.09.2018.
//

#ifndef GAMES_RENDERABLE_HPP
#define GAMES_RENDERABLE_HPP

#include "Renderer.hpp"

#include "../util/Pair.hpp"

class Renderable
{
    friend class Renderer;

private:
    virtual std::vector<Renderable*> render(SDL_Renderer* renderer) = 0;
};

#endif //GAMES_RENDERABLE_HPP
