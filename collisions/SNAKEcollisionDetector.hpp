//
// Created by Busiu on 20.10.2018.
//

#ifndef GAMES_SNAKECOLLISIONDETECTOR_HPP
#define GAMES_SNAKECOLLISIONDETECTOR_HPP

#include "../Libraries.hpp"

#include "../objects/SNAKEmap.hpp"

namespace snake
{
    enum class CollisionResult
    {
        WALL_HIT,
        APPLE_EATEN,
        NOTHING
    };

    class CollisionDetector {
    private:

    public:
        CollisionResult checkCollisions(Map* map);

    private:
        CollisionResult checkCollisions(Snake* snake, TileMap* tileMap);
        CollisionResult checkCollisions(Snake* snake, Apple* apple);
    };
}



#endif //GAMES_SNAKECOLLISIONDETECTOR_HPP
