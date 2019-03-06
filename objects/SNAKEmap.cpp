//
// Created by Busiu on 15.09.2018.
//

#include "SNAKEmap.hpp"

namespace snake
{
    Map::Map(int scale, std::shared_ptr<Renderer> renderer, TextureContainer& textureContainer) :
    textureContainer(textureContainer)
    {
        this->scale = scale;
        this->snake = std::make_shared<Snake>();
        this->tileMap = std::make_shared<TileMap>(scale, renderer->getRenderer());

        std::cout << renderer.use_count() << std::endl;

        this->apple = std::make_shared<Apple>(tileMap->getEmptyArea(), AppleKind::APPLE, scale, textureContainer);
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

    std::shared_ptr<Apple> Map::getApple()
    {
        return apple;
    }
    std::shared_ptr<Snake> Map::getSnake()
    {
        return snake;
    }
    std::shared_ptr<TileMap> Map::getTileMap()
    {
        return tileMap;
    }

    std::vector<Renderable*> Map::render(SDL_Renderer* renderer)
    {
        std::vector<Renderable*> kids;
        kids.push_back(apple.get());
        kids.push_back(snake.get());
        kids.push_back(tileMap.get());

        return kids;
    }
}
