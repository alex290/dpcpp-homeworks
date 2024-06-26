#pragma once

#include "observer.h"
#include <fstream>

class FatalErrorLog : public Observer
{
public:
private:
    void onFatalError(const std::string &message)
    {
        std::cout << GetDateTime() << "\tFATAL ERROR: " <<  message << std::endl;
        // чтения
        std::string line;
        std::string text;

        std::ifstream in("log.txt");
        if (in.is_open())
        {
            while (std::getline(in, line))
            {
                text += line + "\n";
            }
        }
        in.close();
        text += GetDateTime() + "\tFATAL ERROR: " + message;

        // Запись
        std::ofstream out;
        out.open("log.txt");
        if (out.is_open())
        {
            out << text << std::endl;
        }
        out.close();
    };
};