#pragma once

#include "text.h"

class Reversed : public Text
{
public:
    explicit Reversed(Text *text_ptr);
    ~Reversed();

    virtual void render(const std::string &text);

private:
    Text *text_ptr_;
};