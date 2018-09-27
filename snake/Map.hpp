//
// Created by Busiu on 15.09.2018.
//

#ifndef GAMES_MAP_HPP
#define GAMES_MAP_HPP

#include "../Libraries.hpp"

#include "../renderer/Renderable.hpp"

#include "Snake.hpp"
#include "TileMap.hpp"

namespace snake
{
    class Map : public Renderable
    {
    private:
        int scale;

        Snake* snake;
        TileMap* tileMap;

    public:
        Map(int scale, SDL_Renderer* renderer);
        ~Map();

        void update();

        void moveSnakeUp();
        void moveSnakeDown();
        void moveSnakeRight();
        void moveSnakeLeft();

    private:
        //Renderable
        std::vector<Renderable*> render(SDL_Renderer* renderer) override;
    };
}



#endif //GAMES_MAP_HPP
