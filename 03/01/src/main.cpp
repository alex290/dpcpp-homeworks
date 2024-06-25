#include "consolecommand.h"
#include "filecommand.h"

void print(LogCommand &command, const std::string &text)
{
    time_t result = time(NULL);

    char buffer[90];
    struct tm *timeinfo = localtime(&result);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    std::string d_time{buffer};
    command.print(d_time + "\t" + text);
}

int main()
{
    ConsoleCommand console;
    FileCommand file("log.txt");
    print(console, "Log");
    print(file, "Log");
    return 0;
}
