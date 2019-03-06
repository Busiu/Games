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
        CollisionResult checkCollisions(std::shared_ptr<Map> map);

    private:
        CollisionResult checkCollisions(std::shared_ptr<Snake> snake,
                                        std::shared_ptr<TileMap> tileMap);
        CollisionResult checkCollisions(std::shared_ptr<Snake> snake,
                                        std::shared_ptr<Apple> apple);
    };
}



#endif //GAMES_SNAKECOLLISIONDETECTOR_HPP
