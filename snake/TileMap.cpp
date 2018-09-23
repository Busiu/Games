//
// Created by Busiu on 23.09.2018.
//

#include "TileMap.hpp"

namespace snake
{
    TileMap::TileMap(int scale, SDL_Renderer* renderer, TileMapStyle tileMapStyle)
    {
        this->scale = scale;
        this->size = new Pair(30, 20);
        createMap(tileMapStyle);
        loadTextures(renderer);
    }

    TileMap::~TileMap()
    {
        deleteMap();
        delete(size);
        delete(obstacleTexture);
    }

    void TileMap::createMap(TileMapStyle tileMapStyle)
    {
        switch(tileMapStyle)
        {
            case TileMapStyle::STANDARD_MAP:
            {
                createStandardMap();
                break;
            }
        }
    }

    void TileMap::createStandardMap()
    {
        int width = size->getX();
        int height = size->getY();

        initMap();
        emptyMap();

        for(int x = 0; x < width; x++)
        {
            tileMap[x][0] = true;
            tileMap[x][height - 1] = true;
        }

        for(int y = 0; y < height; y++)
        {
            tileMap[0][y] = true;
            tileMap[width - 1][y] = true;
        }
    }

    void TileMap::initMap()
    {
        int width = size->getX();
        int height = size->getY();

        tileMap = new bool*[width];
        for(int x = 0; x < width; x++)
        {
            tileMap[x] = new bool[height];
        }
    }

    void TileMap::emptyMap()
    {
        int width = size->getX();
        int height = size->getY();

        for(int x = 0; x < width; x++)
        {
            for(int y = 0; y < height; y++)
            {
                tileMap[x][y] = false;
            }
        }
    }

    void TileMap::loadTextures(SDL_Renderer* renderer)
    {
        obstacleTexture = new FileTexture(renderer, "../assets/textures/brick.png");
    }

    void TileMap::deleteMap()
    {
        int width = size->getX();

        for(int x = 0; x < width; x++)
        {
            delete(tileMap[x]);
        }
        delete(tileMap);
    }

    std::vector<Renderable*> TileMap::render(SDL_Renderer* renderer)
    {
        std::vector<Renderable*> kids;

        int width = size->getX();
        int height = size->getY();
        for(int x = 0; x < width; x++)
        {
            for(int y = 0; y < height; y++)
            {
                renderTile(x, y, scale, renderer);
            }
        }

        return kids;
    }

    void TileMap::renderTile(int x, int y, int scale, SDL_Renderer* renderer)
    {
        if(tileMap[x][y])
        {
            SDL_Rect renderQuad = {x * scale, y * scale, scale, scale};
            SDL_RenderCopy(renderer, obstacleTexture->getTexture(), nullptr, &renderQuad);
        }
    }
}
