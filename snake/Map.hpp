//
// Created by Busiu on 15.09.2018.
//

#ifndef GAMES_MAP_HPP
#define GAMES_MAP_HPP

#include "../libraries.h"

#include "../math/Pair.h"

#include "../textures/ChunkTexture.hpp"

namespace snake
{
    enum class MapStyle
    {
        STANDARD_MAP
    };

    class Map
    {
    private:
        const static int scale = 20;
        bool** map;
        Pair* size;
        ChunkTexture* obstacleTexture;

    public:
        Map(Pair* size, SDL_Renderer* renderer, MapStyle mapStyle = MapStyle::STANDARD_MAP);
        ~Map();

        void render(SDL_Renderer* renderer);

    private:
        //Constructor
        void createMap(MapStyle mapStyle);
        void loadTextures(SDL_Renderer* renderer);

        void createStandardMap();
        void initMap();
        void emptyMap();
        void deleteMap();

        //Render
        void renderMap(SDL_Renderer* renderer);

    };
}



#endif //GAMES_MAP_HPP
