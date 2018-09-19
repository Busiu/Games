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

    int getX() const;
    int getY() const;

    Pair& operator += (const Pair& pair);
};


#endif //GAMES_PAIR_HPP
