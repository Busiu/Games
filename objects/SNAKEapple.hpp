//
// Created by Busiu on 10.10.2018.
//

#ifndef GAMES_APPLE_HPP
#define GAMES_APPLE_HPP

#include "../Libraries.hpp"

#include "../renderer/Renderable.hpp"

#include "../textures/FileTexture.hpp"

#include "../util/Position.hpp"

#include "SNAKEsnake.hpp"
#include "../containers/SNAKEtextureContainer.hpp"

namespace snake
{
    enum class AppleKind
    {
        APPLE,
        APPLE_SUPER
    };

    class Apple : public Renderable
    {
    private:
        AppleKind appleKind;
        int scale;
        Position<int> position;

        FileTexture* appleTexture;

    public:
        Apple(Position<int> position, AppleKind appleKind, int scale, TextureContainer& textureContainer);

        void gotEaten(Snake* snake);

    private:
        //Renderable
        std::vector<Renderable*> render(SDL_Renderer* renderer) override;

        //GotEaten
        void gotEatenApple(Snake* snake);
        void gotEatenAppleSuper(Snake* snake);
    };
}

#endif //GAMES_APPLE_HPP
