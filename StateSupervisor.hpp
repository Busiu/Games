//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_STATESUPERVISOR_HPP
#define GAMES_STATESUPERVISOR_HPP

#include "Libraries.hpp"

#include "containers/OptionContainer.hpp"
#include "renderer/Renderer.hpp"

#include "states/SnakeState.hpp"
#include "states/MenuState.hpp"
#include "states/OptionState.hpp"
#include "states/State.hpp"
#include "states/States.hpp"

class StateSupervisor {
private:
    std::unique_ptr<State> currentState;

    std::shared_ptr<OptionContainer> optionContainer;
    std::shared_ptr<Renderer> renderer;

public:
    bool init();
    void run();

private:
    //Init
    bool initOptionContainer();
    bool initRenderer();

};


#endif //GAMES_STATESUPERVISOR_HPP
