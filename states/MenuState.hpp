//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_MENUSTATE_HPP
#define GAMES_MENUSTATE_HPP

#include "../Libraries.hpp"

#include "../objects/ColorText.hpp"
#include "../objects/Text.hpp"

#include "../textures/Texture.hpp"

#include "../util/Position.hpp"

#include "State.hpp"
#include "States.hpp"

class MenuState : public State {
private:
    enum Text{
        START_TEXT = 0,
        OPTIONS_TEXT,
        EXIT_TEXT,
        TOTAL_TEXT
    };

    //Font of menu captions
    TTF_Font* font;

    //Menu's texts
    std::array<ColorText*, TOTAL_TEXT> options;

    //Current higlighted text
    int highlightedText = START_TEXT;

public:
    MenuState(OptionContainer* optionContainer, Renderer* windowContainer) :
            State(optionContainer, windowContainer){}

private:
    void load() override;
    int run() override;
    void close() override;

    //Load
    void loadFonts();
    void loadOptions();
    void loadBackground();
    void initialState();

    //Run
    int handleEvents() override;
    void moveDown();
    void moveUp();
    int pressEnter();
    void clear() override;
    void render() override;
    void update() override;
};


#endif //GAMES_MENUSTATE_HPP
