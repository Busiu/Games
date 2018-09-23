//
// Created by Busiu on 23.09.2018.
//

#ifndef GAMES_TILEMAP_HPP
#define GAMES_TILEMAP_HPP

#include "../Libraries.hpp"

#include "../renderer/Renderable.hpp"

#include "../textures/FileTexture.hpp"

namespace snake
{
    enum class TileMapStyle
    {
        STANDARD_MAP
    };

    class TileMap : public Renderable
    {
    private:
        int scale;
        Pair* size;
        bool** tileMap;
        FileTexture* obstacleTexture;

    public:
        TileMap(int scale, SDL_Renderer* renderer, TileMapStyle tileMapStyle = TileMapStyle::STANDARD_MAP);
        ~TileMap();

    private:
        //Constructor
        void createMap(TileMapStyle tileMapStyle);
        void loadTextures(SDL_Renderer* renderer);

        //Create map
        void createStandardMap();
        void initMap();
        void emptyMap();

        void deleteMap();

        //Renderable
        std::vector<Renderable*> render(SDL_Renderer* renderer) override;
        void renderTile(int x, int y, int scale, SDL_Renderer* renderer);
    };
}




#endif //GAMES_TILEMAP_HPP
