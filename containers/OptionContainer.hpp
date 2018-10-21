//
// Created by Busiu on 12.09.2018.
//

#ifndef GAMES_OPTIONCONTAINER_HPP
#define GAMES_OPTIONCONTAINER_HPP

#include "../Libraries.hpp"
#include "../util/Types.hpp"

class OptionContainer {
private:
    int currentResolution = 1;
    const static int noResolutions = 9;
    std::array<Resolution, noResolutions> resolutions;

    int fpsCap = 60;

public:
    OptionContainer();

    Resolution getCertainResolution(int index);
    int getCurrentResolution();
    int getNoResolutions();
    Resolution getWindowResolution();
    int getFpsCap();

    void setCurrentResolution(int currentResolution);
};


#endif //GAMES_OPTIONCONTAINER_HPP
