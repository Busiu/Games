//
// Created by Busiu on 09.09.2018.
//

#include "Exception.hpp"

Exception::Exception(std::string name)
{
    this->name = name;
}

std::string Exception::getMessage()
{
    std::stringstream message;

    message.str("");
    message << "An exception ";
    message << name;
    message << " occured. Application is being shut down.";

    return message.str();
}
