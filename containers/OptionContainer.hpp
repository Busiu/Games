//
// Created by Busiu on 12.09.2018.
//

#ifndef GAMES_OPTIONCONTAINER_HPP
#define GAMES_OPTIONCONTAINER_HPP

#include "../Libraries.hpp"
#include "../math/Pair.hpp"

class OptionContainer {
private:
    const static int noResolutions = 9;
    int currentResolution = 1;
    std::array<Pair*, noResolutions> resolutions;

public:
    OptionContainer();
    ~OptionContainer();

    Pair* getResolution(int index);
    int getNoResolutions();
    int getWindowHeight();
    int getWindowWidth();

    void setCurrentResolution(int currentResolution);
};


#endif //GAMES_OPTIONCONTAINER_HPP
