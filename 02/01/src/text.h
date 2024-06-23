#pragma once

#include <iostream>
#include <algorithm>

class Text
{
public:
    Text();
    ~Text();

    virtual void render(const std::string &text);
    virtual void render(const std::string &link, const std::string &text);

private:
    
};