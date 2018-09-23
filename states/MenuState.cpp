//
// Created by Busiu on 09.09.2018.
//

#include "MenuState.hpp"

void MenuState::load()
{
    loadFonts();
    loadOptions();
    loadBackground();
    initialState();
}

void MenuState::loadFonts()
{
    font = TTF_OpenFont("../assets/fonts/Racing Hoodlums.ttf", 30);
    if(font == nullptr)
    {
        throw Exception("Loading font");
    }
}

void MenuState::loadOptions()
{
    Pair* position = nullptr;
    TextTexture* textTexture = nullptr;

    //START
    textTexture = new TextTexture(renderer->getRenderer(), "START", {0x00, 0xFF, 0x00, 0xFF}, font);
    position = new Pair(optionContainer->getWindowResolution(), TOTAL_TEXT, START_TEXT);
    options[START_TEXT] = new ColorText(textTexture, position, Justification::CENTERED);

    //OPTIONS
    textTexture = new TextTexture(renderer->getRenderer(), "OPTIONS", {0x00, 0xFF, 0x00, 0xFF}, font);
    position = new Pair(optionContainer->getWindowResolution(), TOTAL_TEXT, OPTIONS_TEXT);
    options[OPTIONS_TEXT] = new ColorText(textTexture, position, Justification::CENTERED);

    //EXIT
    textTexture = new TextTexture(renderer->getRenderer(), "EXIT", {0x00, 0xFF, 0x00, 0xFF}, font);
    position = new Pair(optionContainer->getWindowResolution(), TOTAL_TEXT, EXIT_TEXT);
    options[EXIT_TEXT] = new ColorText(textTexture, position, Justification::CENTERED);

}

void MenuState::loadBackground()
{

}

void MenuState::initialState()
{
    options[START_TEXT]->setColor(0xFF, 0x00, 0x00);
}



int MenuState::run()
{
    while(true)
    {
        int NEXT_STATE = handleEvents();
        if(NEXT_STATE < CURRENT_STATE)
        {
            return NEXT_STATE;
        }

        clear();
        render();
        update();
    }
}

int MenuState::handleEvents()
{
    while (SDL_PollEvent(&event) != 0)
    {
        //User requests quit
        if (event.type == SDL_QUIT)
        {
            return EXIT_STATE;
        }

        //User's keyboard requests
        const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
        if(currentKeyStates[SDL_SCANCODE_UP])
        {
            moveUp();
        }
        else if(currentKeyStates[SDL_SCANCODE_DOWN])
        {
            moveDown();
        }
        else if(currentKeyStates[SDL_SCANCODE_RETURN])
        {
            return pressEnter();
        }
    }

    //If no action we back to current state
    return CURRENT_STATE;
}

void MenuState::moveDown()
{
    options[highlightedText]->setColor(0xFF, 0xFF, 0xFF);
    highlightedText = (highlightedText + 1) % TOTAL_TEXT;
    options[highlightedText]->setColor(0xFF, 0x00, 0x00);
}

void MenuState::moveUp()
{
    options[highlightedText]->setColor(0xFF, 0xFF, 0xFF);
    highlightedText = (highlightedText + TOTAL_TEXT - 1) % TOTAL_TEXT;
    options[highlightedText]->setColor(0xFF, 0x00, 0x00);
}

int MenuState::pressEnter()
{
    switch(highlightedText)
    {
        case START_TEXT:
        {
            return SNAKE_STATE;
        }
        case OPTIONS_TEXT:
        {
            return OPTIONS_STATE;
        }
        case EXIT_TEXT:
        {
            return EXIT_STATE;
        }
        default: {}
    }

    return CURRENT_STATE;
}

void MenuState::clear()
{
    renderer->clear();
}

void MenuState::render()
{
    renderer->render(options[START_TEXT]);
    renderer->render(options[OPTIONS_TEXT]);
    renderer->render(options[EXIT_TEXT]);
}

void MenuState::update()
{
    renderer->update();
}



void MenuState::close()
{
    //Forgetting font
    TTF_CloseFont(font);

    //Forgetting texts
    for(int i = 0; i < TOTAL_TEXT; i++)
    {
        delete(options[i]);
    }
}
