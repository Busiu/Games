//
// Created by Busiu on 11.09.2018.
//

#ifndef GAMES_OPTIONSTATE_HPP
#define GAMES_OPTIONSTATE_HPP

#include "../Libraries.hpp"

#include "../objects/ColorText.hpp"
#include "../objects/Text.hpp"

#include "../textures/Texture.hpp"

#include "../util/Pair.hpp"
#include "../util/StringCreator.hpp"

#include "State.hpp"
#include "States.hpp"

class OptionState : public State {
private:
    enum Options{
        RESOLUTION_TEXT = 0,
        VOLUME_TEXT,
        TOTAL_TEXT
    };

    //Font of option captions
    TTF_Font* font;

    //All textures of option captions
    std::array<ColorText*, TOTAL_TEXT> options;
    std::array<Text*, TOTAL_TEXT> optionValues;

    //Current highlighted text
    int highlightedText = RESOLUTION_TEXT;
    int currentResolution = optionContainer->getCurrentResolution();

public:
    OptionState(OptionContainer* optionContainer, Renderer* renderer) :
            State(optionContainer, renderer){}

private:
    void load() override;
    int run() override;
    void close() override;

    //Load
    void loadFonts();
    void loadOptions();
    void loadOptionValues();
    void loadBackground();
    void initialState();

    //Run
    int handleEvents() override;
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void changeOptionResolution();
    void pressEnter();
    void clear() override;
    void render() override;
    void update() override;
};


#endif //GAMES_OPTIONSTATE_HPP
