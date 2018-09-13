//
// Created by Busiu on 12.09.2018.
//

#ifndef GAMES_OPTIONCONTAINER_H
#define GAMES_OPTIONCONTAINER_H

#include "../Libraries.h"

class OptionContainer {
private:
    SDL_Renderer* renderer;



    int WINDOW_HEIGHT = 480;
    int WINDOW_WIDTH = 640;

public:
    SDL_Renderer* getRenderer();
    int getWindowHeight();
    int getWindowWidth();

    void setRenderer(SDL_Renderer* renderer);
};


#endif //GAMES_OPTIONCONTAINER_H
