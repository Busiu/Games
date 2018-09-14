#include <iostream>

#include "Libraries.h"

#include "Application.h"
#include "Exception.h"

#include "states/State.h"
class State;

using namespace std;

int main(int argc, char ** argv)
{
    Application app;

    try
    {
        app.start();
    }
    catch(Exception &e)
    {
        cout << e.getMessage() << endl;
    }

    return 0;
}