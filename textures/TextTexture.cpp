//
// Created by Busiu on 09.09.2018.
//

#include "TextTexture.hpp"

TextTexture::TextTexture(SDL_Renderer* renderer, std::string textureText, SDL_Color textureColor, TTF_Font* textureFont)
: Texture()
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

TextTexture::~TextTexture()
{
    SDL_DestroyTexture(texture);
}
