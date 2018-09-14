//
// Created by Busiu on 09.09.2018.
//

#include "Application.h"

void Application::start()
{
    load();
    run();
    close();
}

void Application::load()
{
    if(!initSDL())
    {
        throw Exception("SDL Initialization");
    }
    if(!initIMG())
    {
        throw Exception("IMG Initialization");
    }
    if(!initTTF())
    {
        throw Exception("TTF Initialization");
    }
    if(!initWindow())
    {
        throw Exception("StateSupervisor Creation");
    }
}

bool Application::initSDL()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return false;
    }

    return true;
}

bool Application::initIMG()
{
    int imgFlags = IMG_INIT_PNG;
    if(!IMG_Init(imgFlags) & imgFlags)
    {
        return false;
    }

    return true;
}

bool Application::initTTF()
{
    if(TTF_Init() == -1)
    {
        return false;
    }

    return true;
}

bool Application::initWindow()
{
    if(!window.init())
    {
        return false;
    }

    return true;
}



void Application::run()
{
    window.run();
}

void Application::close()
{
    freeMemory();
    quitModules();
}

void Application::freeMemory()
{
    window.free();
}

void Application::quitModules()
{
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}