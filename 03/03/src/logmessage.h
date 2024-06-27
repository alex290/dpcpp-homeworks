#pragma once

#include <iostream>

class LogMessage
{
public:
    enum Type
    {
        WARNING,
        ERROR,
        FATAL_ERROR,
        UNKNOWN
    };
    LogMessage() { typeMess = LogMessage::UNKNOWN; };

    virtual void setNext(LogMessage *logMessage) {
        logMessage_ = logMessage;
    }

    // virtual Type type() const;
    // virtual const std::string &message() const;
    virtual void set_log(const std::string &message, const Type &type)
    {
        // std::cout << message << std::endl;
        if (type == typeMess)
        {
            mess_log(message);
        }
        else if (logMessage_ != nullptr)
        {
            logMessage_->set_log(message, type);
        }
    };

protected:
    Type typeMess;
    LogMessage *logMessage_ = nullptr;

    virtual void mess_log(const std::string &message)
    {
        throw std::runtime_error(GetDateTime() + "\tUnknown error: "+ message);
    }
    
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