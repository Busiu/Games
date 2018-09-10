//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_EXCEPTION_H
#define GAMES_EXCEPTION_H

#include "Libraries.h"

using namespace std;

class Exception : public exception {
private:
    string name;

public:
    Exception(string name);

    string getMessage();
};


#endif //GAMES_EXCEPTION_H
