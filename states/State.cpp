//
// Created by Busiu on 09.09.2018.
//

#include "State.h"

int State::start()
{
    int nextState;

    load();
    nextState = run();
    close();

    return nextState;
}
