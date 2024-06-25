#pragma once

#include "logcommand.h"

class ConsoleCommand : public LogCommand
{
public:
    void print(const std::string &message) override {
        std::cout << message << std::endl;
    };

private:

};