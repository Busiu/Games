//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_TEXTURE_HPP
#define GAMES_TEXTURE_HPP

#include "../Libraries.hpp"

class Texture {
protected:
    SDL_Texture* texture;

    int width;
    int height;

public:
    virtual void free();
    virtual void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* dstRect = nullptr) = 0;

    void setColor(Uint32 red, Uint32 green, Uint32 blue);

    int getWidth();
    int getHeight();
};


#endif //GAMES_TEXTURE_HPP
