#pragma once

#include <iostream>
#include <ctime>

class LogCommand
{
public:
   virtual ~LogCommand() = default;
   virtual void print(const std::string &message) = 0;
};