//
// Created by Busiu on 05.10.2018.
//

#include "SNAKEsnakeChunk.hpp"

namespace snake
{
    SnakeChunk::SnakeChunk(Position<double> end,
                           Position<double> beg,
                           Speed<double> speed,
                           SDL_Color& color,
                           int& thickness,
                           Direction direction) :
    end(end),
    beg(beg),
    speed(speed),
    color(color),
    thickness(thickness)
    {
        this->direction = direction;
    }

    void SnakeChunk::move()
    {
        beg.update(speed);
    }
    void SnakeChunk::shorten()
    {
        end.update(speed);
    }

    Position<double> SnakeChunk::getEnd()
    {
        return end;
    }
    Position<double> SnakeChunk::getBeg()
    {
        return beg;
    }
    double SnakeChunk::getLength()
    {
        return Position<double>::getDistance(end, beg);
    }

    std::vector<Renderable*> SnakeChunk::render(SDL_Renderer* renderer)
    {
        std::vector <Renderable*> kids;
        Position tmpA(end);
        Position tmpB(beg);
        Position<double>::sortPositions(tmpA, tmpB);

        SDL_Rect fillRect = RenderAssistant::getRenderRect(tmpA, tmpB, thickness);
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, &fillRect);

        return kids;
    }
}
