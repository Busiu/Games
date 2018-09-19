//
// Created by Busiu on 15.09.2018.
//

#ifndef GAMES_CHUNKTEXTURE_HPP
#define GAMES_CHUNKTEXTURE_HPP

#include "../Libraries.hpp"
#include "../Exception.hpp"

#include "Texture.hpp"

class ChunkTexture : public Texture{
private:

public:
    ChunkTexture(SDL_Renderer* renderer, std::string textureText);
    ~ChunkTexture();

    void free() override;
};


#endif //GAMES_CHUNKTEXTURE_HPP
