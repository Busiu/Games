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
    Position<int>* position;
    Justification justification;

public:
    Text(TextTexture* text, Position<int>* position, Justification justification);
    virtual ~Text();

    Position<int>* getPosition();

    void setPosition(Position<int>* position);
    void shift(Position<int>* vector);

protected:
    //Renderable
    std::vector<Renderable*> render(SDL_Renderer* renderer) override;
    void renderCentered(SDL_Renderer* renderer);
    void renderFlushedLeft(SDL_Renderer* renderer);
};


#endif //GAMES_TEXT_HPP
