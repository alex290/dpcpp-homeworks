#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Observer
{
public:
    virtual void onWarning(const std::string &message){};
    virtual void onError(const std::string &message){};
    virtual void onFatalError(const std::string &message){};
    virtual std::string GetDateTime()
    {
        time_t result = time(NULL);

        char buffer[90];
        struct tm *timeinfo = localtime(&result);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        std::string d_time{buffer};
        return d_time;
    };
};
