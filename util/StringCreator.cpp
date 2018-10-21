//
// Created by Busiu on 19.09.2018.
//

#include "StringCreator.hpp"

std::string StringCreator::stringFromResolution(Resolution resolution)
{
    std::stringstream text;

    text.str("");
    text << resolution.first << "x" << resolution.second;

    return text.str();
}
