//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_MENUSTATE_HPP
#define GAMES_MENUSTATE_HPP

#include "../Libraries.hpp"

#include "../objects/ColorText.hpp"
#include "../objects/Text.hpp"

#include "../textures/Texture.hpp"

#include "../util/Font.hpp"
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
    std::unique_ptr<Font> font;

    //Menu's texts
    std::array<ColorText*, TOTAL_TEXT> options;

    //Current higlighted text
    int highlightedText = START_TEXT;

public:
    MenuState(const std::shared_ptr<OptionContainer> optionContainer,
              const std::shared_ptr<Renderer> renderer);

private:
    void load() override;
    States run() override;
    void close() override;

    //Load
    void loadFonts();
    void loadOptions();
    void loadBackground();
    void initialState();

    //Run
    States handleEvents() override;
    void moveDown();
    void moveUp();
    States pressEnter();
    void clearScreen() override;
    void renderObjects() override;
    void updateScreen() override;
};


#endif //GAMES_MENUSTATE_HPP
