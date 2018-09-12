//
// Created by Busiu on 11.09.2018.
//

#include <iostream>
#include "OptionState.h"

OptionState::OptionState(OptionContainer* optionContainer)
{
    this->optionContainer = optionContainer;
}



void OptionState::load()
{
    loadFonts();
    loadTextures();
    loadBackground();
    initialState();
}

void OptionState::loadFonts()
{
    font = TTF_OpenFont("../assets/fonts/Racing Hoodlums.ttf", 30);
    if(font == nullptr)
    {
        throw Exception("Loading font");
    }
}

void OptionState::loadTextures()
{
    TextTexture* textTexture = nullptr;
    textures = new Texture*[TOTAL_TEXT];

    //Buttons:
    //RESOLUTION
    textTexture = new TextTexture();
    textTexture->load(optionContainer->getRenderer(), "RESOLUTION", {0x00, 0xFF, 0x00, 0xFF}, font);
    textures[RESOLUTION_TEXT] = textTexture;

    //VOLUME
    textTexture = new TextTexture();
    textTexture->load(optionContainer->getRenderer(), "VOLUME", {0x00, 0xFF, 0x00, 0xFF}, font);
    textures[VOLUME_TEXT] = textTexture;
}

void OptionState::loadBackground()
{

}

void OptionState::initialState()
{
    textures[RESOLUTION_TEXT]->setColor(0xFF, 0, 0);
}



int OptionState::run()
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

int OptionState::handleEvents()
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
        else if(currentKeyStates[SDL_SCANCODE_ESCAPE])
        {
            return MENU_STATE;
        }
    }

    //Returning something else than "EXIT_STATE"
    return CURRENT_STATE;
}

void OptionState::moveDown()
{
    textures[highlightedText]->setColor(0xFF, 0xFF, 0xFF);
    highlightedText = (highlightedText + 1) % TOTAL_TEXT;
    textures[highlightedText]->setColor(0xFF, 0x00, 0x00);
}

void OptionState::moveUp()
{
    textures[highlightedText]->setColor(0xFF, 0xFF, 0xFF);
    highlightedText = (highlightedText + TOTAL_TEXT - 1) % TOTAL_TEXT;
    textures[highlightedText]->setColor(0xFF, 0x00, 0x00);
}

void OptionState::clear()
{
    SDL_SetRenderDrawColor(optionContainer->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(optionContainer->getRenderer());
}

void OptionState::render()
{
    for(int i = 0; i < TOTAL_TEXT; i++)
    {
        textures[i]->render(optionContainer->getRenderer(),
                            (optionContainer->getWindowWidth() - textures[i]->getWidth()) / 2 ,
                            optionContainer->getWindowHeight() * i/ TOTAL_TEXT);
    }
}

void OptionState::update()
{
    SDL_RenderPresent(optionContainer->getRenderer());
}



void OptionState::close()
{
    //Forgetting font
    TTF_CloseFont(font);

    //Forgetting textures
    for(int i = 0; i < TOTAL_TEXT; i++)
    {
        textures[i]->free();
    }
    delete[] textures;
}