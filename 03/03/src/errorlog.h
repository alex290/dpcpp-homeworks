#pragma once

#include "warninglog.h"
#include <fstream>

class ErrorLog : public WarningLog
{
public:
    ErrorLog() { typeMess = LogMessage::ERROR; };

protected:
    virtual void mess_log(const std::string &message)
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
    }
};