//
// Created by Busiu on 30.09.2018.
//

#ifndef GAMES_RENDERASSISTANT_HPP
#define GAMES_RENDERASSISTANT_HPP

#include "../Libraries.hpp"

#include "../util/Position.hpp"

class RenderAssistant {
private:

public:
    static SDL_Rect getRenderRect(Position<double> topLeft, Position<double> bottomRight, int thickness);

private:

};


#endif //GAMES_RENDERASSISTANT_HPP
