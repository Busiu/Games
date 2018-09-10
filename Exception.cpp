//
// Created by Busiu on 09.09.2018.
//

#include "Exception.h"

Exception::Exception(string name)
{
    this->name = name;
}

string Exception::getMessage()
{
    stringstream message;

    message.str("");
    message << "An exception ";
    message << name;
    message << " occured. Application is being shut down.";

    return message.str();
}
