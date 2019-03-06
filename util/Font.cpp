//
// Created by Busiu on 06.03.2019.
//

#include "Font.hpp"

Font::Font(std::string path, int size)
{
    font = TTF_OpenFont(path.c_str(), size);
    if(font == nullptr)
    {
        throw Exception("Loading font");
    }
}

Font::~Font()
{
    TTF_CloseFont(font);
}

TTF_Font* Font::getFont()
{
    return font;
}
