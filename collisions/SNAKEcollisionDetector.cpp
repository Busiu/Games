//
// Created by Busiu on 20.10.2018.
//

#include "SNAKEcollisionDetector.hpp"

namespace snake
{
    CollisionResult CollisionDetector::checkCollisions(Map* map)
    {
        CollisionResult result;

        result = checkCollisions(map->getSnake(), map->getTileMap());
        if(result != CollisionResult::NOTHING)
        {
            return result;
        }
        result = checkCollisions(map->getSnake(), map->getApple());
        if(result != CollisionResult::NOTHING)
        {
            return result;
        }

        return CollisionResult::NOTHING;
    }

    CollisionResult CollisionDetector::checkCollisions(Snake* snake, TileMap* tileMap)
    {
        Position<int> snakeTile = tileMap->getTile(snake->getHeadPosition());
        bool** map = tileMap->getTileMap();
        int mapWidth = tileMap->getSize().getX();
        int mapHeight = tileMap->getSize().getY();
        int X = snakeTile.getX();
        int Y = snakeTile.getY();
        for(int x = X - 1; x <= X + 1; x++)
        {
            for(int y = Y - 1; y <= Y + 1; y++)
            {
                if(x < mapWidth && y < mapHeight && x >= 0 && y >= 0)
                {
                    if(map[x][y])
                    {
                        return CollisionResult::WALL_HIT;
                    }
                }
            }
        }

        return CollisionResult::NOTHING;
    }
    CollisionResult CollisionDetector::checkCollisions(Snake* snake, Apple* apple)
    {
        //TODO: Snake-Apple collision
        return CollisionResult::NOTHING;
    }
}
