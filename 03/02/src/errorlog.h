#pragma once

#include "observer.h"
#include <fstream>

class ErrorLog : public Observer
{
private:
    void onError(const std::string &message)
    {
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
        text += GetDateTime() + "\tERROR: " + message;

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