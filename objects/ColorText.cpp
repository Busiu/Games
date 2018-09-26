//
// Created by Busiu on 18.09.2018.
//

#include "ColorText.hpp"

void ColorText::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
    SDL_SetTextureColorMod(text->getTexture(), red, green, blue);
}
