//
// Created by Busiu on 12.09.2018.
//

#include "OptionContainer.h"

OptionContainer::OptionContainer(Window* window)
{
    this->window = window;

    resolutions = new Pair*[noResolutions];
    resolutions[0] = new Pair(320, 240);
    resolutions[1] = new Pair(640, 480);
    resolutions[2] = new Pair(960, 720);
    resolutions[3] = new Pair(1280, 960);
    resolutions[4] = new Pair(1280, 1024);
    resolutions[5] = new Pair(1600, 1200);
    resolutions[6] = new Pair(1280, 720);
    resolutions[7] = new Pair(1600, 900);
    resolutions[8] = new Pair(1920, 1080);
}

OptionContainer::~OptionContainer()
{
    for(int i = 0; i < noResolutions; i++)
    {
        delete resolutions[i];
    }
    delete [] resolutions;
}

Pair** OptionContainer::getResolutions()
{
    return resolutions;
}

int OptionContainer::getNoResolutions()
{
    return noResolutions;
}

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

void OptionContainer::setResolution(Pair* resolution)
{
    this->WINDOW_WIDTH = resolution->getX();
    this->WINDOW_HEIGHT = resolution->getY();

    window->setResolution();
}