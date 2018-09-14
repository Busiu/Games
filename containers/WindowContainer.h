//
// Created by Busiu on 14.09.2018.
//

#ifndef GAMES_WINDOWCONTAINER_H
#define GAMES_WINDOWCONTAINER_H

#include "../Libraries.h"
#include "../Exception.h"

#include "../math/Pair.h"

class WindowContainer {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    WindowContainer(int WINDOW_WIDTH, int WINDOW_HEIGHT);
    ~WindowContainer();

    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();

    void setWindow(SDL_Window* window);
    void setRenderer(SDL_Renderer* renderer);
    void setResolution(Pair* resolution);

private:
    //Constructor
    bool initWindow(int WINDOW_WIDTH, int WINDOW_HEIGHT);
    bool initRenderer();

    //Destructor
    void destroyWindow();
    void destroyRenderer();
};


#endif //GAMES_WINDOWCONTAINER_H
