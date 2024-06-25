#pragma once

#include "logcommand.h"
#include <fstream>

class FileCommand : public LogCommand
{
public:
    FileCommand(const std::string &file) : file_(file){};
    void print(const std::string &message) override
    {
        // чтения
        std::string line;
        std::string text;

        std::ifstream in(file_);
        if (in.is_open())
        {
            while (std::getline(in, line))
            {
                text += line + "\n";
            }
        }
        in.close();
        text += message;

        // Запись
        std::ofstream out;
        out.open(file_);
        if (out.is_open())
        {
            out << text << std::endl;
        }
        out.close();
    };

private:
    std::string file_;
};