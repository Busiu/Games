//
// Created by Busiu on 12.09.2018.
//

#ifndef GAMES_OPTIONCONTAINER_H
#define GAMES_OPTIONCONTAINER_H

#include "../Libraries.h"
#include "../math/Pair.h"

class OptionContainer {
private:
    SDL_Renderer* renderer;

    Pair** resolutions;
    int noResolutions = 9;

    int WINDOW_HEIGHT = 480;
    int WINDOW_WIDTH = 640;

public:
    OptionContainer();
    ~OptionContainer();

    SDL_Renderer* getRenderer();
    Pair** getResolutions();
    int getNoResolutions();
    int getWindowHeight();
    int getWindowWidth();

    void setRenderer(SDL_Renderer* renderer);
};


#endif //GAMES_OPTIONCONTAINER_H
