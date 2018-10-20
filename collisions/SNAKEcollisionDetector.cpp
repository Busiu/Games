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

    CollisionResult CollisionDetector::checkCollisions(Snake* snake, TileMap* _tileMap)
    {
        Position<int> snakeHeadTile = _tileMap->getTile(snake->getHeadPosition());
        bool** tileMap = _tileMap->getTileMap();
        int tileMapWidth = _tileMap->getSize().getX();
        int tileMapHeight = _tileMap->getSize().getY();
        int X = snakeHeadTile.getX();
        int Y = snakeHeadTile.getY();
        for(int x = X - 1; x <= X + 1; x++)
        {
            for(int y = Y - 1; y <= Y + 1; y++)
            {
                if(x < tileMapWidth && y < tileMapHeight && x >= 0 && y >= 0)
                {
                    if(tileMap[x][y])
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
