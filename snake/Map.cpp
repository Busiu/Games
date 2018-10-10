//
// Created by Busiu on 15.09.2018.
//

#include "Map.hpp"

namespace snake
{
    Map::Map(int scale, Renderer* renderer, TextureContainer& textureContainer) :
    textureContainer(textureContainer)
    {
        this->scale = scale;
        this->snake = new Snake();
        this->tileMap = new TileMap(scale, renderer->getRenderer());

        this->apple = new Apple(tileMap->getEmptyArea(), AppleKind::APPLE, scale, textureContainer);
    }
    Map::~Map()
    {
        delete(snake);
        delete(tileMap);
        delete(apple);
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
        kids.push_back(apple);
        kids.push_back(snake);
        kids.push_back(tileMap);

        return kids;
    }
}
