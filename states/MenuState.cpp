//
// Created by Busiu on 09.09.2018.
//

#include "MenuState.h"

MenuState::MenuState(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}



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
    textures = new Texture*[TOTAL_TEXT];

    //Buttons:
    //START
    textTexture = new TextTexture();
    textTexture->load(renderer, "START", {0x00, 0xFF, 0x00, 0xFF}, font);
    textures[START_TEXT] = textTexture;

    //OPTIONS
    textTexture = new TextTexture();
    textTexture->load(renderer, "OPTIONS", {0x00, 0xFF, 0x00, 0xFF}, font);
    textures[OPTIONS_TEXT] = textTexture;

    //EXIT
    textTexture = new TextTexture();
    textTexture->load(renderer, "EXIT", {0x00, 0xFF, 0x00, 0xFF}, font);
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
        if(handleEvents() == EXIT_STATE)
        {
            return EXIT_STATE;
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
    }

    //Returning something else than "EXIT_STATE"
    return 1;
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

void MenuState::clear()
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

void MenuState::render()
{
    for(int i = 0; i < TOTAL_TEXT; i++)
    {
        textures[i]->render(renderer, (640 - textures[i]->getWidth()) / 2 , 480 * i/ TOTAL_TEXT);
    }
}

void MenuState::update()
{
    SDL_RenderPresent(renderer);
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
    delete[] textures;
}
