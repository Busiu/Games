//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_TEXTTEXTURE_H
#define GAMES_TEXTTEXTURE_H

#include "../Libraries.h"
#include "../Exception.h"

#include "Texture.h"


class TextTexture : public Texture {
private:

public:
    void load(SDL_Renderer* renderer, std::string textureText, SDL_Color textureColor, TTF_Font* textureFont);
    void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* dstRect = nullptr) override;
    void free() override;

private:
};


#endif //GAMES_TEXTTEXTURE_H
