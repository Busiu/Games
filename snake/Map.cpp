//
// Created by Busiu on 15.09.2018.
//

#include "Map.hpp"

namespace snake
{
    Map::Map(Pair* size, SDL_Renderer* renderer, MapStyle mapStyle)
    {
        this->size = size;
        loadTextures(renderer);
        createMap(mapStyle);
    }

    Map::~Map()
    {
        delete(this->size);
        deleteMap();
    };

    void Map::createMap(MapStyle mapStyle)
    {
        switch(mapStyle)
        {
            case MapStyle::STANDARD_MAP:
            {
                createStandardMap();
                break;
            }
        }
    }

    void Map::createStandardMap()
    {
        int width = size->getX();
        int height = size->getY();

        initMap();
        emptyMap();

        for(int x = 0; x < width; x++)
        {
            map[x][0] = true;
            map[x][height - 1] = true;
        }

        for(int y = 0; y < height; y++)
        {
            map[0][y] = true;
            map[width - 1][y] = true;
        }
    }

    void Map::initMap()
    {
        int width = size->getX();
        int height = size->getY();

        map = new bool*[width];
        for(int x = 0; x < width; x++)
        {
            map[x] = new bool[height];
        }
    }

    void Map::emptyMap()
    {
        int width = size->getX();
        int height = size->getY();

        for(int x = 0; x < width; x++)
        {
            for(int y = 0; y < height; y++)
            {
                map[x][y] = false;
            }
        }
    }

    void Map::deleteMap()
    {
        int width = size->getX();

        for(int x = 0; x < width; x++)
        {
            delete(map[x]);
        }
        delete(map);
    }

    void Map::loadTextures(SDL_Renderer* renderer)
    {
        obstacleTexture = new ChunkTexture();
        obstacleTexture->load(renderer, "../assets/textures/brick.png");
    }



    void Map::render(SDL_Renderer* renderer)
    {
        renderMap(renderer);
    }

    void Map::renderMap(SDL_Renderer* renderer)
    {
        int width = size->getX();
        int height = size->getY();
        SDL_Rect dstRect = {0, 0, scale, scale};

        for(int x = 0; x < width; x++)
        {
            for(int y = 0; y < height; y++)
            {
                if(map[x][y])
                {
                    obstacleTexture->render(renderer, x * scale, y * scale, &dstRect);
                }
            }
        }
    }
}
