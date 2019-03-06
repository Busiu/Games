//
// Created by Busiu on 06.03.2019.
//

#ifndef GAMES_FONT_HPP
#define GAMES_FONT_HPP

#include "../Exception.hpp"
#include "../Libraries.hpp"

class Font
{
private:
    TTF_Font* font;

public:
    explicit Font(std::string path, int size);
    ~Font();

    TTF_Font* getFont();

};


#endif //GAMES_FONT_HPP
