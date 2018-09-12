//
// Created by Busiu on 12.09.2018.
//

#include "OptionContainer.h"

int OptionContainer::getWindowHeight()
{
    return WINDOW_HEIGHT;
}

int OptionContainer::getWindowWidth()
{
    return WINDOW_WIDTH;
}

SDL_Renderer* OptionContainer::getRenderer()
{
    return renderer;
}

void OptionContainer::setRenderer(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}