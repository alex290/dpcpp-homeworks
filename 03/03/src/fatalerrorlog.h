#pragma once

#include "errorlog.h"

class FatalErrorLog : public ErrorLog
{
public:
    FatalErrorLog() { typeMess = LogMessage::FATAL_ERROR; };

protected:

    virtual void mess_log(const std::string &message)
    {
        throw std::runtime_error(GetDateTime() + "\tFatal error: "+ message);
    }
};