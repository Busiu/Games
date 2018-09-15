//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_MENUSTATE_HPP
#define GAMES_MENUSTATE_HPP

#include "../Libraries.hpp"

#include "../textures/Texture.hpp"
#include "../textures/TextTexture.hpp"

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

    //All textures of menu captions
    std::array<Texture*, TOTAL_TEXT> textures;

    //Current higlighted text
    int highlightedText = START_TEXT;

public:
    MenuState(OptionContainer* optionContainer, WindowContainer* windowContainer) :
            State(optionContainer, windowContainer){}

private:
    void load() override;
    int run() override;
    void close() override;

    //Load
    void loadFonts();
    void loadTextures();
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
