//
// Created by Busiu on 23.09.2018.
//

#include "TileMap.hpp"

namespace snake
{
    TileMap::TileMap(int scale, SDL_Renderer* renderer, TileMapStyle tileMapStyle)
    {
        this->scale = scale;
        this->size = new Position<int>(30, 20);
        this->tileMapStyle = tileMapStyle;
        createMap(tileMapStyle);
        loadTextures(renderer);
    }
    TileMap::~TileMap()
    {
        deleteMap();
        delete(size);
        delete(obstacleTexture);
    }

    Position<int> TileMap::getEmptyArea()
    {
        int noEmptyChunks = 0;
        std::vector <Position<int>> chunks;
        int Y = size->getY();
        int X = size->getX();
        for(int y = 0; y < Y; y++)
        {
            for(int x = 0; x < X; x++)
            {
                if(!tileMap[x][y])
                {
                    noEmptyChunks++;
                    Position<int> tmp(x, y);
                    chunks.push_back(tmp);
                }
            }
        }

        if(noEmptyChunks == 0)
        {
            return Position<int>(0,0);
        }

        std::cout << noEmptyChunks << std::endl;

        std::default_random_engine generator(static_cast<unsigned> (time(nullptr) * clock()));
        std::uniform_int_distribution<int> distributionOfBlocks{1, noEmptyChunks};
        std::uniform_int_distribution<int> distributionOfPixels{1, scale};
        int randomBlock = distributionOfBlocks(generator);
        int randomPixel = distributionOfPixels(generator);

        std::cout << randomBlock << std::endl;
        std::cout << randomPixel << std::endl;

        Position<int> result(chunks[randomBlock].getX() * scale + randomPixel,
                             chunks[randomBlock].getY() * scale + randomPixel);
        return result;
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
