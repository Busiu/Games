#include <iostream>

#include "Libraries.h"

#include "Application.h"
#include "Exception.h"

#include "states/State.h"

int main(int argc, char ** argv)
{
    Application app;

    try
    {
        app.start();
    }
    catch(Exception &e)
    {
        std::cout << e.getMessage() << std::endl;
    }

    return 0;
}