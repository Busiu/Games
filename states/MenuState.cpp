//
// Created by Busiu on 09.09.2018.
//

#include <iostream>
#include "MenuState.hpp"

void MenuState::load()
{
    loadFonts();
    loadTextures();
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

void MenuState::loadTextures()
{
    TextTexture* textTexture = nullptr;

    //Buttons:
    //START
    textTexture = new TextTexture();
    textTexture->load(windowContainer->getRenderer(), "START", {0x00, 0xFF, 0x00, 0xFF}, font);
    textures[START_TEXT] = textTexture;

    //OPTIONS
    textTexture = new TextTexture();
    textTexture->load(windowContainer->getRenderer(), "OPTIONS", {0x00, 0xFF, 0x00, 0xFF}, font);
    textures[OPTIONS_TEXT] = textTexture;

    //EXIT
    textTexture = new TextTexture();
    textTexture->load(windowContainer->getRenderer(), "EXIT", {0x00, 0xFF, 0x00, 0xFF}, font);
    textures[EXIT_TEXT] = textTexture;
}

void MenuState::loadBackground()
{

}

void MenuState::initialState()
{
    textures[START_TEXT]->setColor(0xFF, 0, 0);
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
    textures[highlightedText]->setColor(0xFF, 0xFF, 0xFF);
    highlightedText = (highlightedText + 1) % TOTAL_TEXT;
    textures[highlightedText]->setColor(0xFF, 0x00, 0x00);
}

void MenuState::moveUp()
{
    textures[highlightedText]->setColor(0xFF, 0xFF, 0xFF);
    highlightedText = (highlightedText + TOTAL_TEXT - 1) % TOTAL_TEXT;
    textures[highlightedText]->setColor(0xFF, 0x00, 0x00);
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
    SDL_SetRenderDrawColor(windowContainer->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(windowContainer->getRenderer());
}

void MenuState::render()
{
    for(int i = 0; i < TOTAL_TEXT; i++)
    {
        textures[i]->render(windowContainer->getRenderer(),
                            (optionContainer->getWindowWidth() - textures[i]->getWidth()) / 2 ,
                            optionContainer->getWindowHeight() * i/ TOTAL_TEXT);
    }
}

void MenuState::update()
{
    SDL_RenderPresent(windowContainer->getRenderer());
}



void MenuState::close()
{
    //Forgetting font
    TTF_CloseFont(font);

    //Forgetting textures
    for(int i = 0; i < TOTAL_TEXT; i++)
    {
        textures[i]->free();
    }
}
