//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_WINDOW_H
#define GAMES_WINDOW_H

#include "Libraries.h"

#include "states/MenuState.h"
#include "states/State.h"
#include "states/States.h"


class Window {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    State* currentState;

    int width = 640;
    int height = 480;

public:
    bool init();
    void run();
    void free();

private:
    //Init
    bool initWindow();
    bool initRenderer();

    //Free
    void destroyWindow();
    void destroyRenderer();
};


#endif //GAMES_WINDOW_H
