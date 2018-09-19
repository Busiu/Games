//
// Created by Busiu on 13.09.2018.
//

#ifndef GAMES_PAIR_HPP
#define GAMES_PAIR_HPP

#include "../Libraries.hpp"

#include "../renderer/Renderable.hpp"

class Pair {
private:
    int x;
    int y;

public:
    Pair(int x, int y);
    Pair(Pair* resolution, int noObjects, int index);

    int getX();
    int getY();

    void shift(Pair& shift);
};


#endif //GAMES_PAIR_HPP
