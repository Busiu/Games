//
// Created by Busiu on 18.09.2018.
//

#ifndef GAMES_COLORTEXT_HPP
#define GAMES_COLORTEXT_HPP

#include "Text.hpp"

class ColorText : public Text {
private:

public:
    ColorText(TextTexture* text, Position<int> position, Justification justification);

    void setColor(Uint8 red, Uint8 green, Uint8 blue);
};


#endif //GAMES_COLORTEXT_HPP
