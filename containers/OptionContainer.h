//
// Created by Busiu on 12.09.2018.
//

#ifndef GAMES_OPTIONCONTAINER_H
#define GAMES_OPTIONCONTAINER_H

#include "../Libraries.h"
#include "../math/Pair.h"
#include "../Window.h"

class Window;

class OptionContainer {
private:
    SDL_Renderer* renderer;
    Window* window;
    Pair** resolutions;
    int noResolutions = 9;
    int WINDOW_HEIGHT = 480;
    int WINDOW_WIDTH = 640;

public:
    OptionContainer(Window* window);
    ~OptionContainer();

    SDL_Renderer* getRenderer();
    Pair** getResolutions();
    int getNoResolutions();
    int getWindowHeight();
    int getWindowWidth();

    void setRenderer(SDL_Renderer* renderer);
    void setResolution(Pair* resolution);
};


#endif //GAMES_OPTIONCONTAINER_H
