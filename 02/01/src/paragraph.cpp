#include "paragraph.h"

Paragraph::Paragraph(Text *text_ptr) : text_ptr_(text_ptr)
{
}

Paragraph::~Paragraph()
{
}

void Paragraph::render(const std::string &text)
{
    std::cout << "<p>";
    text_ptr_->render(text);
    std::cout << "</p>\n";
}
