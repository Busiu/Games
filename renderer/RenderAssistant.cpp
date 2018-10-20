//
// Created by Busiu on 30.09.2018.
//

#include "RenderAssistant.hpp"

SDL_Rect RenderAssistant::getRenderRect(Position<double> topLeft, Position<double> bottomRight, int thickness)
{
    SDL_Rect result = {
            static_cast<int> (topLeft.getX()) - thickness,
            static_cast<int> (-topLeft.getY()) - thickness,
            static_cast<int> (bottomRight.getX() - topLeft.getX()) + (2 * thickness),
            static_cast<int> ((-bottomRight.getY()) - (-topLeft.getY())) + (2 * thickness)
    };

    return result;
}
