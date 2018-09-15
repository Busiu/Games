//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_EXCEPTION_H
#define GAMES_EXCEPTION_H

#include "Libraries.h"

class Exception : public std::exception {
private:
    std::string name;

public:
    Exception(std::string name);

    std::string getMessage();
};


#endif //GAMES_EXCEPTION_H
