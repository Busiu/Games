//
// Created by Busiu on 19.09.2018.
//

#include "StringCreator.hpp"

std::string StringCreator::stringFromResolution(Position<int>* resolution)
{
    std::stringstream text;

    text.str("");
    text << resolution->getX() << "x" << resolution->getY();

    return text.str();
}
