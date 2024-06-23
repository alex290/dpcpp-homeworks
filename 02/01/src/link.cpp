#include "link.h"

Link::Link(Text *text_ptr) : text_ptr_(text_ptr)
{

}

Link::~Link()
{

}

void Link::render(const std::string &link, const std::string &text)
{
    std::cout << "<a href=" << link <<">";
    text_ptr_->render(link, text);
    std::cout << "</a>\n";
}
