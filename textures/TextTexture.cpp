//
// Created by Busiu on 09.09.2018.
//

#include "TextTexture.h"

void TextTexture::load(SDL_Renderer* renderer, string textureText, SDL_Color textureColor, TTF_Font* textureFont)
{
    free();

    SDL_Surface* textSurface = TTF_RenderText_Solid(textureFont, textureText.c_str(), textureColor);
    if(textSurface == nullptr)
    {
        throw Exception("Loading Texture");
    }

    texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if(texture == nullptr)
    {
        throw Exception("Creating Surface");
    }

    width = textSurface->w;
    height = textSurface->h;

    SDL_FreeSurface(textSurface);
}

void TextTexture::render(SDL_Renderer* renderer, int x, int y)
{
    SDL_Rect renderQuad = {x, y, width, height};

    SDL_RenderCopy(renderer, texture, nullptr, &renderQuad);
}

void TextTexture::free()
{
    Texture::free();
}