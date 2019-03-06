//
// Created by Busiu on 10.10.2018.
//

#include "SNAKEtextureContainer.hpp"

namespace snake
{
    TextureContainer::TextureContainer(const std::shared_ptr<Renderer> renderer)
    {
        apple = new FileTexture(renderer->getRenderer(), "../assets/textures/apple.png");
        appleSuper = new FileTexture(renderer->getRenderer(), "../assets/textures/appleSuper.png");
    }
    TextureContainer::~TextureContainer()
    {
        delete(apple);
        delete(appleSuper);
    }

    FileTexture* TextureContainer::getAppleTexture()
    {
        return apple;
    }
    FileTexture* TextureContainer::getAppleSuperTexture()
    {
        return appleSuper;
    }
}
