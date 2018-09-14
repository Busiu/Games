//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_WINDOW_H
#define GAMES_WINDOW_H

#include "Libraries.h"

#include "containers/OptionContainer.h"

#include "states/MenuState.h"
#include "states/OptionState.h"
#include "states/State.h"
#include "states/States.h"

class OptionContainer;
class State;
class OptionState;
class MenuState;


class Window {
private:
    SDL_Window* window;

    State* currentState;

    OptionContainer* optionContainer;

public:
    bool init();
    void run();
    void free();
    void setResolution();

private:
    //Init
    bool initOptionContainer();
    bool initWindow();
    bool initRenderer();

    //Free
    void destroyWindow();
    void destroyOptionContainer();
};


#endif //GAMES_WINDOW_H
