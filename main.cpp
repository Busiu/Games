#include <iostream>

#include "Application.h"
#include "Exception.h"

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