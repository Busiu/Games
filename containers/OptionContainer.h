//
// Created by Busiu on 12.09.2018.
//

#ifndef GAMES_OPTIONCONTAINER_H
#define GAMES_OPTIONCONTAINER_H

#include "../Libraries.h"
#include "../math/Pair.h"

class OptionContainer {
private:
    Pair** resolutions;
    int noResolutions = 9;
    int currentResolution = 1;

public:
    OptionContainer();
    ~OptionContainer();

    Pair** getResolutions();
    int getNoResolutions();
    int getWindowHeight();
    int getWindowWidth();

    void setCurrentResolution(int currentResolution);
};


#endif //GAMES_OPTIONCONTAINER_H
