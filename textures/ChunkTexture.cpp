//
// Created by Busiu on 15.09.2018.
//

#include "ChunkTexture.hpp"

void ChunkTexture::load(SDL_Renderer* renderer, std::string textureText)
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

void ChunkTexture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* dstRect)
{
    SDL_Rect renderQuad = {x, y, width, height};
    if(dstRect != nullptr)
    {
        renderQuad.w = dstRect->w;
        renderQuad.h = dstRect->h;
    }

    SDL_RenderCopy(renderer, texture, nullptr, &renderQuad);
}

void ChunkTexture::free()
{
    Texture::free();
}