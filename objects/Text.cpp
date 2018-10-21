//
// Created by Busiu on 18.09.2018.
//

#include "Text.hpp"

Text::Text(TextTexture* text, Position<int> position, Justification justification)
{
    this->text = text;
    this->position = position;
    this->justification = justification;
}

Text::~Text()
{
    delete(text);
}

void Text::setPosition(Position<int> position)
{
    this->position = position;
}

void Text::shift(Position<int>& vector)
{
    position.shift(vector);
}

std::vector<Renderable*> Text::render(SDL_Renderer* renderer)
{
    std::vector<Renderable*> kids;

    if(justification == Justification::CENTERED)
    {
        renderCentered(renderer);
    }
    else if(justification == Justification::FLUSH_LEFT)
    {
        renderFlushedLeft(renderer);
    }

    return kids;
}

void Text::renderCentered(SDL_Renderer* renderer)
{
    SDL_Rect renderQuad = {
            position.getX() - text->getWidth() / 2,
            position.getY(),
            text->getWidth(),
            text->getHeight()
    };

    SDL_RenderCopy(renderer, text->getTexture(), nullptr, &renderQuad);
}

void Text::renderFlushedLeft(SDL_Renderer* renderer)
{
    SDL_Rect renderQuad = {
            position.getX(),
            position.getY(),
            text->getWidth(),
            text->getHeight()
    };

    SDL_RenderCopy(renderer, text->getTexture(), nullptr, &renderQuad);
}