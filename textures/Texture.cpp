//
// Created by Busiu on 09.09.2018.
//

#include "Texture.hpp"

Texture::~Texture()
{
    SDL_DestroyTexture(texture);
}

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

SDL_Texture* Texture::getTexture()
{
    return texture;
}

int Texture::getWidth()
{
    return width;
}

int Texture::getHeight()
{
    return height;
}
