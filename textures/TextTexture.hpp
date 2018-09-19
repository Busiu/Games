//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_TEXTTEXTURE_HPP
#define GAMES_TEXTTEXTURE_HPP

#include "../Libraries.hpp"
#include "../Exception.hpp"

#include "Texture.hpp"


class TextTexture : public Texture {
private:

public:
    TextTexture(SDL_Renderer* renderer, std::string textureText, SDL_Color textureColor, TTF_Font* textureFont);
    ~TextTexture();

    void free() override;

private:
};


#endif //GAMES_TEXTTEXTURE_HPP