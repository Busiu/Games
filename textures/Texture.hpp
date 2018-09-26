//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_TEXTURE_HPP
#define GAMES_TEXTURE_HPP

#include "../Libraries.hpp"

class Texture {
protected:
    SDL_Texture* texture = nullptr;

    int width;
    int height;

public:
    virtual ~Texture();

    void free();

    SDL_Texture* getTexture();

    int getWidth();
    int getHeight();
};


#endif //GAMES_TEXTURE_HPP
