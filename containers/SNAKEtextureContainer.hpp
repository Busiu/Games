//
// Created by Busiu on 10.10.2018.
//

#ifndef GAMES_TEXTURECONTAINER_HPP
#define GAMES_TEXTURECONTAINER_HPP

#include "../Libraries.hpp"

#include "../renderer/Renderer.hpp"

#include "../textures/FileTexture.hpp"

namespace snake
{
    class TextureContainer
    {
    private:
        FileTexture* apple;
        FileTexture* appleSuper;

    public:
        TextureContainer(const std::shared_ptr<Renderer> renderer);
        ~TextureContainer();

        FileTexture* getAppleTexture();
        FileTexture* getAppleSuperTexture();
    };
}

#endif //GAMES_TEXTURECONTAINER_HPP
