#include "fatalerrorlog.h"
int main()
{
    LogMessage logMessage;

    WarningLog warningLog;
    warningLog.setNext(&logMessage);

    ErrorLog errorLog;
    errorLog.setNext(&warningLog);

    FatalErrorLog fatalErrorLog;
    fatalErrorLog.setNext(&errorLog);

    fatalErrorLog.set_log("log", LogMessage::ERROR);
    fatalErrorLog.set_log("log", LogMessage::WARNING);

    try
    {
        fatalErrorLog.set_log("log", LogMessage::FATAL_ERROR);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        fatalErrorLog.set_log("log", LogMessage::UNKNOWN);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}