//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_APPLICATION_H
#define GAMES_APPLICATION_H

#include "Libraries.h"

#include "Exception.h"
#include "Window.h"

class Application {

private:
    //Application window
    Window window;

public:
    //Start of application
    void start();

private:
    //Initialization of modules
    void load();
    //Actual application
    void run();
    //Closing modules
    void close();

    //Load
    bool initSDL();
    bool initIMG();
    bool initTTF();
    bool initWindow();

    //Close
    void freeMemory();
    void quitModules();
};


#endif //GAMES_APPLICATION_H
