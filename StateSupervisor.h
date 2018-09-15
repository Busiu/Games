//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_STATESUPERVISOR_H
#define GAMES_STATESUPERVISOR_H

#include "Libraries.h"

#include "containers/OptionContainer.h"
#include "containers/WindowContainer.h"

#include "snake/SnakeState.hpp"
#include "states/MenuState.h"
#include "states/OptionState.h"
#include "states/State.h"
#include "states/States.h"

class StateSupervisor {
private:
    State* currentState;

    OptionContainer* optionContainer;
    WindowContainer* windowContainer;

public:
    bool init();
    void run();
    void free();

private:
    //Init
    bool initOptionContainer();
    bool initWindowContainer();

    //Free
    void destroyOptionContainer();
    void destroyWindowContainer();
};


#endif //GAMES_STATESUPERVISOR_H
