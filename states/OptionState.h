//
// Created by Busiu on 11.09.2018.
//

#ifndef GAMES_OPTIONSTATE_H
#define GAMES_OPTIONSTATE_H

#include "../libraries.h"

#include "../textures/Texture.h"
#include "../textures/TextTexture.h"

#include "State.h"
#include "States.h"

class OptionState : public State {
private:
    //Font of option captions
    TTF_Font* font;

    //All textures of option captions
    Texture** textures;

    //Current highlighted text
    int highlightedText = RESOLUTION_TEXT;
    int currentResolution = 1;

    enum text{
        RESOLUTION_TEXT = 0,
        VOLUME_TEXT,
        TOTAL_TEXT
    };

public:
    OptionState(OptionContainer* optionContainer, WindowContainer* windowContainer) :
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
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void pressEnter();
    void clear() override;
    void render() override;
    void update() override;
};


#endif //GAMES_OPTIONSTATE_H
