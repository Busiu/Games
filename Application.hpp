//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_APPLICATION_HPP
#define GAMES_APPLICATION_HPP

#include "Libraries.hpp"

#include "Exception.hpp"
#include "StateSupervisor.hpp"

class Application {

private:
    //Application window
    StateSupervisor stateSupervisor;

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
    bool initStateSupervisor();

    //Close
    void quitModules();
};


#endif //GAMES_APPLICATION_HPP
