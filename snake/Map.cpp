//
// Created by Busiu on 15.09.2018.
//

#include "Map.hpp"

namespace snake
{
    Map::Map(int scale, SDL_Renderer* renderer)
    {
        this->scale = scale;
        this->snake = new Snake();
        this->tileMap = new TileMap(scale, renderer);
    }
    Map::~Map()
    {
        delete(snake);
        delete(tileMap);
    }

    void Map::update()
    {
        snake->update();
    }

    void Map::moveSnakeUp()
    {
        snake->moveUp();
    }
    void Map::moveSnakeDown()
    {
        snake->moveDown();
    }
    void Map::moveSnakeRight()
    {
        snake->moveRight();
    }
    void Map::moveSnakeLeft()
    {
        snake->moveLeft();
    }

    std::vector<Renderable*> Map::render(SDL_Renderer* renderer)
    {
        std::vector<Renderable*> kids;
        kids.push_back(snake);
        kids.push_back(tileMap);

        return kids;
    }
}
