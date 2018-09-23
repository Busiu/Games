//
// Created by Busiu on 15.09.2018.
//

#ifndef GAMES_FILETEXTURE_HPP
#define GAMES_FILETEXTURE_HPP

#include "../Libraries.hpp"
#include "../Exception.hpp"

#include "Texture.hpp"

class FileTexture : public Texture{
private:

public:
    FileTexture(SDL_Renderer* renderer, std::string textureText);
    ~FileTexture();

    void free() override;
};


#endif //GAMES_FILETEXTURE_HPP
