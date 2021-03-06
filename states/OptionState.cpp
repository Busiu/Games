//
// Created by Busiu on 11.09.2018.
//

#include "OptionState.hpp"

OptionState::OptionState(const std::shared_ptr<OptionContainer> optionContainer,
                         const std::shared_ptr<Renderer> renderer) :
        State(optionContainer, renderer)
        {}

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
    font = std::make_unique<Font>("../assets/fonts/Racing Hoodlums.ttf", 30);
}

void OptionState::loadOptions()
{
    //RESOLUTION
    TextTexture* resolutionTexture = new TextTexture(renderer->getRenderer(), "RESOLUTION", {0x00, 0xFF, 0x00, 0xFF}, font);
    Position<int> resolutionPosition(optionContainer->getWindowResolution(), TOTAL_TEXT, RESOLUTION_TEXT);
    options[RESOLUTION_TEXT] = new ColorText(resolutionTexture, resolutionPosition, Justification::CENTERED);

    //VOLUME
    TextTexture* volumeTexture = new TextTexture(renderer->getRenderer(), "VOLUME", {0x00, 0xFF, 0x00, 0xFF}, font);
    Position<int> volumePosition(optionContainer->getWindowResolution(), TOTAL_TEXT, VOLUME_TEXT);
    options[VOLUME_TEXT] = new ColorText(volumeTexture, volumePosition, Justification::CENTERED);

}

void OptionState::loadOptionValues()
{
    std::string value;
    TextTexture* textTexture = nullptr;
    Position<int> vector(200, 0);

    //RESOLUTION
    value = StringCreator::stringFromResolution(optionContainer->getCertainResolution(currentResolution));
    textTexture = new TextTexture(renderer->getRenderer(), value, {0x00, 0xFF, 0x00, 0xFF}, font);
    Position<int> resolutionPosition(optionContainer->getWindowResolution(), TOTAL_TEXT, RESOLUTION_TEXT);
    optionValues[RESOLUTION_TEXT] = new Text(textTexture, resolutionPosition, Justification::CENTERED);
    optionValues[RESOLUTION_TEXT]->shift(vector);

    //VOLUME
    value = "10";
    textTexture = new TextTexture(renderer->getRenderer(), value, {0x00, 0xFF, 0x00, 0xFF}, font);
    Position<int> volumePosition(optionContainer->getWindowResolution(), TOTAL_TEXT, VOLUME_TEXT);
    optionValues[VOLUME_TEXT] = new Text(textTexture, volumePosition, Justification::CENTERED);
    optionValues[VOLUME_TEXT]->shift(vector);
}

void OptionState::loadBackground()
{
    //TODO: implement
}

void OptionState::initialState()
{
    options[RESOLUTION_TEXT]->setColor(0xFF, 0x00, 0x00);
}



States OptionState::run()
{
    while(true)
    {
        fpsCapper->start();

        States NEXT_STATE = handleEvents();
        if(NEXT_STATE != States::CURRENT_STATE)
        {
            return NEXT_STATE;
        }

        clearScreen();
        renderObjects();
        updateScreen();

        fpsCapper->end();
        fpsCapper->wait();
    }
}

States OptionState::handleEvents()
{
    while (SDL_PollEvent(&event) != 0)
    {
        //User requests quit
        if (event.type == SDL_QUIT)
        {
            return States::EXIT_STATE;
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
            return States::MENU_STATE;
        }
    }

    //Returning something else than "EXIT_STATE"
    return States::CURRENT_STATE;
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

    std::string value;
    TextTexture* textTexture = nullptr;
    Position<int> vector(200, 0);

    value = StringCreator::stringFromResolution(optionContainer->getCertainResolution(currentResolution));
    textTexture = new TextTexture(renderer->getRenderer(), value, {0x00, 0xFF, 0x00, 0xFF}, font);
    Position<int> resolutionPosition(optionContainer->getWindowResolution(), TOTAL_TEXT, RESOLUTION_TEXT);
    optionValues[RESOLUTION_TEXT] = new Text(textTexture, resolutionPosition, Justification::CENTERED);
    optionValues[RESOLUTION_TEXT]->shift(vector);
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
            Position vector(200, 0);

            options[i]->setPosition(Position<int>(optionContainer->getWindowResolution(), TOTAL_TEXT, i));
            optionValues[i]->setPosition(Position<int>(optionContainer->getWindowResolution(), TOTAL_TEXT, i));
            optionValues[i]->shift(vector);
        }
    }
}

void OptionState::clearScreen()
{
    renderer->clear();
}

void OptionState::renderObjects()
{
    renderer->render(options[RESOLUTION_TEXT]);
    renderer->render(options[VOLUME_TEXT]);
    renderer->render(optionValues[RESOLUTION_TEXT]);
    renderer->render(optionValues[VOLUME_TEXT]);
}

void OptionState::updateScreen()
{
    renderer->update();
}



void OptionState::close()
{
    //Forgetting texts
    for(int i = 0; i < TOTAL_TEXT; i++)
    {
        delete(options[i]);
        delete(optionValues[i]);
    }
}