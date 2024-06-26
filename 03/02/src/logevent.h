#pragma once

#include "observer.h"

class LogEvent
{
public:
    void registerObserver(Observer *observer)
    {
        observers.push_back(observer);
    }

    void RemoveObserver(Observer *observer)
    {
        auto it = std::remove(observers.begin(), observers.end(), observer);
        observers.erase(it, observers.end());
    }

    void warning(const std::string &message)
    {
        for (Observer *observer : observers)
        {
            observer->onWarning(message);
        }
    };

    void error(const std::string &message)
    {
        for (Observer *observer : observers)
        {
            observer->onError(message);
        }
    };

    void fatalError(const std::string &message)
    {
        for (Observer *observer : observers)
        {
            observer->onFatalError(message);
        }
    };

private:
    std::vector<Observer *> observers;
};
