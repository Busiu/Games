//
// Created by Busiu on 30.09.2018.
//

#ifndef GAMES_RENDERASSISTANT_HPP
#define GAMES_RENDERASSISTANT_HPP

#include "../Libraries.hpp"

#include "../util/Position.hpp"

class RenderAssistant {
public:
    static SDL_Rect getRenderRect(Position<double> positionA, Position<double> positionB, int thickness);

private:
    static SDL_Rect getVerticalRect(Position<double> positionA, Position<double> positionB, int thickness);
    static SDL_Rect getHorizontalRect(Position<double> positionA, Position<double> positionB, int thickness);
};


#endif //GAMES_RENDERASSISTANT_HPP
