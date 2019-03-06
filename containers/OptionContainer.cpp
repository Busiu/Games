//
// Created by Busiu on 12.09.2018.
//

#include "OptionContainer.hpp"

OptionContainer::OptionContainer()
{
    resolutions[0] = Resolution(640, 360);
    resolutions[1] = Resolution(960, 540);
    resolutions[2] = Resolution(1280, 720);
    resolutions[3] = Resolution(1600, 900);
    resolutions[4] = Resolution(1920, 1080);
}

Resolution OptionContainer::getCertainResolution(int index)
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

Resolution OptionContainer::getWindowResolution()
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
