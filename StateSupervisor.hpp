//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_STATESUPERVISOR_HPP
#define GAMES_STATESUPERVISOR_HPP

#include "Libraries.hpp"

#include "containers/OptionContainer.hpp"
#include "renderer/Renderer.hpp"

#include "snake/SnakeState.hpp"
#include "states/MenuState.hpp"
#include "states/OptionState.hpp"
#include "states/State.hpp"
#include "states/States.hpp"

class StateSupervisor {
private:
    State* currentState;

    OptionContainer* optionContainer;
    Renderer* renderer;

public:
    bool init();
    void run();
    void free();

private:
    //Init
    bool initOptionContainer();
    bool initRenderer();

    //Free
    void destroyOptionContainer();
    void destroyRenderer();
};


#endif //GAMES_STATESUPERVISOR_HPP
