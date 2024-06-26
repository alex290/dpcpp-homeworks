#include "logevent.h"
#include "warninglog.h"
#include "errorlog.h"
#include "fatalerrorlog.h"

int main()
{
    LogEvent logEvent;

    WarningLog warningLog;
    ErrorLog errorLog;
    FatalErrorLog fatalErrorLog;

    logEvent.registerObserver(&warningLog);
    logEvent.registerObserver(&errorLog);
    logEvent.registerObserver(&fatalErrorLog);

    logEvent.warning("log");
    logEvent.error("log");
    logEvent.fatalError("log");
    logEvent.RemoveObserver(&warningLog);
    logEvent.RemoveObserver(&errorLog);
    logEvent.RemoveObserver(&fatalErrorLog);

    return 0;
}