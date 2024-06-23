#pragma once

#include "text.h"

class Paragraph : public Text
{
public:
    explicit Paragraph(Text *text_ptr);
    ~Paragraph();

    virtual void render(const std::string &text);

private:
    Text *text_ptr_;
};