//
// Created by Busiu on 05.10.2018.
//

#ifndef GAMES_SNAKECHUNK_HPP
#define GAMES_SNAKECHUNK_HPP

#include "../Libraries.hpp"

#include "../renderer/Renderable.hpp"
#include "../renderer/RenderAssistant.hpp"

#include "../util/Direction.hpp"
#include "../util/Position.hpp"
#include "../util/Speed.hpp"

namespace snake
{
    class SnakeChunk : public Renderable
    {
    private:
        Position<double> end;
        Position<double> beg;
        Speed<double> speed;
        SDL_Color& color;
        int& thickness;
        Direction direction;

    public:
        SnakeChunk(Position<double> end,
                   Position<double> beg,
                   Speed<double> speed,
                   SDL_Color& color,
                   int& thickness,
                   Direction direction);

        void move();
        void shorten();

        Position<double> getEnd();
        Position<double> getBeg();
        double getLength();

    private:
        std::vector<Renderable*> render(SDL_Renderer* renderer) override;

    };
}

#endif //GAMES_SNAKECHUNK_HPP
