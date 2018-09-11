//
// Created by Busiu on 11.09.2018.
//

#ifndef GAMES_OPTIONSTATE_H
#define GAMES_OPTIONSTATE_H

#include "../libraries.h"
#include "../textures/Texture.h"
#include "../textures/TextTexture.h"
#include "State.h"

class OptionState : public State {
private:
    //Font of option captions
    TTF_Font* font;

    //All textures of option captions
    Texture** textures;

    //Current highlighted text
    int highlightedText = RESOLUTION_TEXT;

    enum text{
        RESOLUTION_TEXT = 0,
        VOLUME_TEXT,
        TOTAL_TEXT
    };

public:
    OptionState(SDL_Renderer* renderer);

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
    void clear() override;
    void render() override;
    void update() override;
};


#endif //GAMES_OPTIONSTATE_H
