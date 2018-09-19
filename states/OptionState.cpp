//
// Created by Busiu on 11.09.2018.
//

#include <iostream>
#include "OptionState.hpp"

void OptionState::load()
{
    loadFonts();
    loadOptions();
    loadOptionValues();
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

void OptionState::loadOptions()
{
    Pair* position = nullptr;
    TextTexture* textTexture = nullptr;

    //RESOLUTION
    textTexture = new TextTexture();
    textTexture->load(renderer->getRenderer(), "RESOLUTION", {0x00, 0xFF, 0x00, 0xFF}, font);
    position = new Pair(optionContainer->getWindowResolution(), TOTAL_TEXT, RESOLUTION_TEXT);
    options[RESOLUTION_TEXT] = new ColorText(textTexture, position, Justification::CENTERED);

    //VOLUME
    textTexture = new TextTexture();
    textTexture->load(renderer->getRenderer(), "VOLUME", {0x00, 0xFF, 0x00, 0xFF}, font);
    position = new Pair(optionContainer->getWindowResolution(), TOTAL_TEXT, VOLUME_TEXT);
    options[VOLUME_TEXT] = new ColorText(textTexture, position, Justification::CENTERED);

}

void OptionState::loadOptionValues()
{
    Pair* position = nullptr;
    Pair shift(200, 0);
    std::stringstream resolution;
    TextTexture* textTexture = nullptr;

    //RESOLUTION
    resolution.str("");
    resolution << optionContainer->getWindowWidth() << "x" << optionContainer->getWindowHeight();
    textTexture = new TextTexture();
    textTexture->load(renderer->getRenderer(), resolution.str(), {0x00, 0xFF, 0x00, 0xFF}, font);
    position = new Pair(optionContainer->getWindowResolution(), TOTAL_TEXT, RESOLUTION_TEXT);
    position->shift(shift);
    optionValues[RESOLUTION_TEXT] = new Text(textTexture, position, Justification::CENTERED);

    //VOLUME
    resolution.str("");
    resolution << 10;
    textTexture = new TextTexture();
    textTexture->load(renderer->getRenderer(), resolution.str(), {0x00, 0xFF, 0x00, 0xFF}, font);
    position = new Pair(optionContainer->getWindowResolution(), TOTAL_TEXT, VOLUME_TEXT);
    position->shift(shift);
    optionValues[VOLUME_TEXT] = new Text(textTexture, position, Justification::CENTERED);
}

void OptionState::loadBackground()
{

}

void OptionState::initialState()
{
    options[RESOLUTION_TEXT]->setColor(0xFF, 0x00, 0x00);
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
        else if(currentKeyStates[SDL_SCANCODE_RIGHT])
        {
            moveRight();
        }
        else if(currentKeyStates[SDL_SCANCODE_LEFT])
        {
            moveLeft();
        }
        else if(currentKeyStates[SDL_SCANCODE_RETURN])
        {
            pressEnter();
        }
        else if(currentKeyStates[SDL_SCANCODE_ESCAPE])
        {
            return MENU_STATE;
        }
    }

    //Returning something else than "EXIT_STATE"
    return CURRENT_STATE;
}

void OptionState::moveUp()
{
    options[highlightedText]->setColor(0xFF, 0xFF, 0xFF);
    highlightedText = (highlightedText + TOTAL_TEXT - 1) % TOTAL_TEXT;
    options[highlightedText]->setColor(0xFF, 0x00, 0x00);
}

void OptionState::moveDown()
{
    options[highlightedText]->setColor(0xFF, 0xFF, 0xFF);
    highlightedText = (highlightedText + 1) % TOTAL_TEXT;
    options[highlightedText]->setColor(0xFF, 0x00, 0x00);
}

void OptionState::moveRight()
{
    if(highlightedText == RESOLUTION_TEXT)
    {
        currentResolution = (currentResolution + 1) % optionContainer->getNoResolutions();
        changeOptionResolution();
    }
}

void OptionState::moveLeft()
{
    if(highlightedText == RESOLUTION_TEXT)
    {
        currentResolution = (currentResolution - 1 + optionContainer->getNoResolutions()) % optionContainer->getNoResolutions();
        changeOptionResolution();
    }
}

void OptionState::changeOptionResolution()
{
    delete(optionValues[RESOLUTION_TEXT]);

    Pair* position = nullptr;
    Pair shift(200, 0);
    std::stringstream resolution;
    TextTexture* textTexture = nullptr;

    resolution.str("");
    resolution << optionContainer->getCertainResolution(currentResolution)->getX()
               << "x" << optionContainer->getCertainResolution(currentResolution)->getY();
    textTexture = new TextTexture();
    textTexture->load(renderer->getRenderer(), resolution.str(), {0x00, 0xFF, 0x00, 0xFF}, font);
    position = new Pair(optionContainer->getWindowResolution(), TOTAL_TEXT, RESOLUTION_TEXT);
    position->shift(shift);
    optionValues[RESOLUTION_TEXT] = new Text(textTexture, position, Justification::CENTERED);
}

void OptionState::pressEnter()
{
    //Changing resolution
    if(highlightedText == RESOLUTION_TEXT)
    {
        renderer->setResolution(optionContainer->getCertainResolution(currentResolution));
        optionContainer->setCurrentResolution(currentResolution);

        //Changing position of option texts
        for(int i = 0; i < TOTAL_TEXT; i++)
        {
            Pair shift(200, 0);

            options[i]->setPosition(new Pair(optionContainer->getWindowResolution(), TOTAL_TEXT, i));
            optionValues[i]->setPosition(new Pair(optionContainer->getWindowResolution(), TOTAL_TEXT, i));
            optionValues[i]->shift(shift);
        }
    }
}

void OptionState::clear()
{
    SDL_SetRenderDrawColor(renderer->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer->getRenderer());
}

void OptionState::render()
{
    renderer->render(options[RESOLUTION_TEXT]);
    renderer->render(options[VOLUME_TEXT]);
    renderer->render(optionValues[RESOLUTION_TEXT]);
    renderer->render(optionValues[VOLUME_TEXT]);
}

void OptionState::update()
{
    SDL_RenderPresent(renderer->getRenderer());
}



void OptionState::close()
{
    //Forgetting font
    TTF_CloseFont(font);

    //Forgetting texts
    for(int i = 0; i < TOTAL_TEXT; i++)
    {
        delete(options[i]);
        delete(optionValues[i]);
    }
}