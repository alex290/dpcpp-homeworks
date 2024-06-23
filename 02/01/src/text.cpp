#include "text.h"

Text::Text()
{

}

Text::~Text()
{

}

void Text::render(const std::string &text)
{
    std::cout << text;
}

void Text::render(const std::string &link, const std::string &text)
{
    std::cout << text;
}
