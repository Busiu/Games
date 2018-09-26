//
// Created by Busiu on 15.09.2018.
//

#include "FileTexture.hpp"

FileTexture::FileTexture(SDL_Renderer *renderer, std::string textureText)
{
    free();

    SDL_Surface* chunkSurface = IMG_Load(textureText.c_str());
    if(chunkSurface == nullptr)
    {
        throw Exception("Loading Texture");
    }

    texture = SDL_CreateTextureFromSurface(renderer, chunkSurface);
    if(texture == nullptr)
    {
        throw Exception("Creating Surface");
    }

    width = chunkSurface->w;
    height = chunkSurface->h;

    SDL_FreeSurface(chunkSurface);
}

FileTexture::~FileTexture()
{
    SDL_DestroyTexture(texture);
}