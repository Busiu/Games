//
// Created by Busiu on 15.09.2018.
//

#include "Map.hpp"

namespace snake
{
    Map::Map(int scale, SDL_Renderer* renderer)
    {
        this->scale = scale;
        this->tileMap = new TileMap(scale, renderer);
    }

    Map::~Map()
    {
        delete(this->tileMap);
    }

    std::vector<Renderable*> Map::render(SDL_Renderer* renderer)
    {
        std::vector<Renderable*> kids;
        kids.push_back(tileMap);

        return kids;
    }
}
