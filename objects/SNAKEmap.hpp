//
// Created by Busiu on 15.09.2018.
//

#ifndef GAMES_MAP_HPP
#define GAMES_MAP_HPP

#include "../Libraries.hpp"

#include "../renderer/Renderable.hpp"

#include "SNAKEapple.hpp"
#include "SNAKEsnake.hpp"
#include "../containers/SNAKEtextureContainer.hpp"
#include "SNAKEtileMap.hpp"

namespace snake
{
    class Map : public Renderable
    {
    private:
        int scale;

        std::shared_ptr<Apple> apple;
        std::shared_ptr<Snake> snake;
        std::shared_ptr<TileMap> tileMap;

        TextureContainer& textureContainer;

    public:
        Map(int scale, std::shared_ptr<Renderer> renderer, TextureContainer& textureContainer);
        ~Map() = default;

        void update();

        void moveSnakeUp();
        void moveSnakeDown();
        void moveSnakeRight();
        void moveSnakeLeft();

        std::shared_ptr<Apple> getApple();
        std::shared_ptr<Snake> getSnake();
        std::shared_ptr<TileMap> getTileMap();

    private:
        //Renderable
        std::vector<Renderable*> render(SDL_Renderer* renderer) override;

    };
}



#endif //GAMES_MAP_HPP
