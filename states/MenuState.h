//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_MENUSTATE_H
#define GAMES_MENUSTATE_H

#include "../libraries.h"

#include "../textures/Texture.h"
#include "../textures/TextTexture.h"

#include "State.h"
#include "States.h"

class MenuState : public State {
private:
    //Font of menu captions
    TTF_Font* font;

    //All textures of menu captions
    Texture** textures;

    //Current higlighted text
    int highlightedText = START_TEXT;

    enum text{
        START_TEXT = 0,
        OPTIONS_TEXT,
        EXIT_TEXT,
        TOTAL_TEXT
    };

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


#endif //GAMES_MENUSTATE_H
