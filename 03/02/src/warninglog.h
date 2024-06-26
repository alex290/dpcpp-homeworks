#pragma once

#include "observer.h"

class WarningLog : public Observer
{
public:
private:
    void onWarning(const std::string &message)
    {
        std::cout << GetDateTime() << "\tWARNING: " <<  message << std::endl;
    };
};