//
// Created by Busiu on 12.09.2018.
//

#ifndef GAMES_OPTIONCONTAINER_HPP
#define GAMES_OPTIONCONTAINER_HPP

#include "../Libraries.hpp"
#include "../util/Pair.hpp"

class OptionContainer {
private:
    int currentResolution = 1;
    const static int noResolutions = 9;
    std::array<Pair*, noResolutions> resolutions;

public:
    OptionContainer();
    ~OptionContainer();

    Pair* getCertainResolution(int index);
    int getCurrentResolution();
    int getNoResolutions();
    int getWindowHeight();
    int getWindowWidth();
    Pair* getWindowResolution();

    void setCurrentResolution(int currentResolution);
};


#endif //GAMES_OPTIONCONTAINER_HPP
