#pragma once

#include "logmessage.h"

class WarningLog : public LogMessage
{
public:
    WarningLog() { typeMess = LogMessage::WARNING; };

protected:
    virtual void mess_log(const std::string &message)
    {
        std::cout << GetDateTime() << "\tWARNING: " << message << std::endl;
    }
};