//
// Created by Busiu on 12.09.2018.
//

#include "OptionContainer.hpp"

OptionContainer::OptionContainer()
{
    resolutions[0] = new Position<int>(320, 240);
    resolutions[1] = new Position<int>(640, 480);
    resolutions[2] = new Position<int>(960, 720);
    resolutions[3] = new Position<int>(1280, 960);
    resolutions[4] = new Position<int>(1280, 1024);
    resolutions[5] = new Position<int>(1600, 1200);
    resolutions[6] = new Position<int>(1280, 720);
    resolutions[7] = new Position<int>(1600, 900);
    resolutions[8] = new Position<int>(1920, 1080);
}
OptionContainer::~OptionContainer()
{
    for(int i = 0; i < noResolutions; i++)
    {
        delete(resolutions[i]);
    }
}

Position<int>* OptionContainer::getCertainResolution(int index)
{
    return resolutions[index];
}

int OptionContainer::getCurrentResolution()
{
    return currentResolution;
}

int OptionContainer::getNoResolutions()
{
    return noResolutions;
}

Position<int>* OptionContainer::getWindowResolution()
{
    return resolutions[currentResolution];
}

int OptionContainer::getFpsCap()
{
    return fpsCap;
}

void OptionContainer::setCurrentResolution(int currentResolution)
{
    this->currentResolution = currentResolution;
}
