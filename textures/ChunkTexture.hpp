//
// Created by Busiu on 15.09.2018.
//

#ifndef GAMES_CHUNKTEXTURE_HPP
#define GAMES_CHUNKTEXTURE_HPP

#include "../Libraries.h"
#include "../Exception.h"

#include "Texture.h"

class ChunkTexture : public Texture{
private:

public:
    void load(SDL_Renderer* renderer, std::string textureText);
    void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* dstRect = nullptr) override;
    void free() override;
};


#endif //GAMES_CHUNKTEXTURE_HPP
