//
// Created by Busiu on 18.09.2018.
//

#ifndef GAMES_TEXT_HPP
#define GAMES_TEXT_HPP

#include "../Libraries.hpp"

#include "../renderer/Renderable.hpp"

#include "../textures/TextTexture.hpp"

enum class Justification{
    CENTERED,
    FLUSH_LEFT
};

class Text : public Renderable{
protected:
    TextTexture* text;
    Pair* position;
    Justification justification;

public:
    Text(TextTexture* text, Pair* position, Justification justification);
    virtual ~Text();

    Pair* getPosition();

    void setPosition(Pair* position);
    void shift(Pair& position);

protected:
    //Renderable
    void render(SDL_Renderer* renderer) override;
    void renderCentered(SDL_Renderer* renderer);
    void renderFlushedLeft(SDL_Renderer* renderer);
};


#endif //GAMES_TEXT_HPP
