//
// Created by Busiu on 10.10.2018.
//

#include "Apple.hpp"

namespace snake
{
    Apple::Apple(Position<int> position, AppleKind appleKind, int scale, TextureContainer& textureContainer) :
    position(position)
    {
        this->appleKind = appleKind;
        this->scale = scale;
        switch(appleKind)
        {
            case AppleKind::APPLE:
            {
                this->appleTexture = textureContainer.getAppleTexture();
                break;
            }
            case AppleKind::APPLE_SUPER:
            {
                this->appleTexture = textureContainer.getAppleSuperTexture();
                break;
            }
        }
    }

    void Apple::gotEaten(Snake* snake)
    {
        switch(appleKind)
        {
            case AppleKind::APPLE:
            {
                gotEatenApple(snake);
                break;
            }
            case AppleKind::APPLE_SUPER:
            {
                gotEatenAppleSuper(snake);
                break;
            }
        }
    }

    std::vector<Renderable*> Apple::render(SDL_Renderer* renderer)
    {
        std::vector<Renderable*> kids;
        SDL_Rect renderQuad = {position.getX(),
                               position.getY(),
                               scale,
                               scale};
        SDL_RenderCopy(renderer, appleTexture->getTexture(), nullptr, &renderQuad);

        return kids;
    }

    void Apple::gotEatenApple(Snake* snake)
    {

    }
    void Apple::gotEatenAppleSuper(Snake* snake)
    {

    }
}
