#pragma once

#include "text.h"

class Link : public Text
{
public:
    explicit Link(Text *text_ptr);
    ~Link();

    virtual void render(const std::string &link, const std::string &text);

private:
    Text *text_ptr_;

};