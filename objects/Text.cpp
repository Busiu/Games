//
// Created by Busiu on 18.09.2018.
//

#include "Text.hpp"

Text::Text(TextTexture* text, Pair* position, Justification justification)
{
    this->text = text;
    this->position = position;
    this->justification = justification;
}

Text::~Text()
{
    free(text);
    free(position);
}

Pair* Text::getPosition()
{
    return position;
}

void Text::setPosition(Pair* position)
{
    delete(this->position);
    this->position = position;
}

void Text::shift(Pair& position)
{
    *this->position += position;
}

void Text::render(SDL_Renderer* renderer)
{
    if(justification == Justification::CENTERED)
    {
        renderCentered(renderer);
    }
    else if(justification == Justification::FLUSH_LEFT)
    {
        renderFlushedLeft(renderer);
    }
}

void Text::renderCentered(SDL_Renderer* renderer)
{
    SDL_Rect renderQuad = {position->getX() - text->getWidth() / 2, position->getY(),
                           text->getWidth(), text->getHeight()};

    SDL_RenderCopy(renderer, text->getTexture(), nullptr, &renderQuad);
}

void Text::renderFlushedLeft(SDL_Renderer* renderer)
{
    SDL_Rect renderQuad = {position->getX(), position->getY(),
                           text->getWidth(), text->getHeight()};

    SDL_RenderCopy(renderer, text->getTexture(), nullptr, &renderQuad);
}