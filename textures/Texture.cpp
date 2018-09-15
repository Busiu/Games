//
// Created by Busiu on 09.09.2018.
//

#include "Texture.hpp"

void Texture::free()
{
    if(texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        width = 0;
        height = 0;
    }
}

void Texture::setColor(Uint32 red, Uint32 green, Uint32 blue)
{
    SDL_SetTextureColorMod(texture, red, green, blue);
}

int Texture::getWidth()
{
    return width;
}

int Texture::getHeight()
{
    return height;
}
