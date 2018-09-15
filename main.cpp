#include <iostream>

#include "Libraries.hpp"

#include "Application.hpp"
#include "Exception.hpp"

#include "states/State.hpp"

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