#include "reversed.h"

Reversed::Reversed(Text *text_ptr) : text_ptr_(text_ptr)
{

}

Reversed::~Reversed()
{

}

void Reversed::render(const std::string &text)
{
    std::string copy(text);
    std::reverse(copy.begin(), copy.end());
    std::cout << copy << "\n";
}
