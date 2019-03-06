//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_TEXTTEXTURE_HPP
#define GAMES_TEXTTEXTURE_HPP

#include "../Libraries.hpp"
#include "../Exception.hpp"

#include "../util/Font.hpp"

#include "Texture.hpp"


class TextTexture : public Texture {
private:

public:
    TextTexture(SDL_Renderer* renderer, std::string textureText, SDL_Color textureColor, std::unique_ptr<Font>& textureFont);
    ~TextTexture();

};


#endif //GAMES_TEXTTEXTURE_HPP
