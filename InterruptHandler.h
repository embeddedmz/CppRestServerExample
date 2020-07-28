#pragma once

#include <condition_variable>
#include <mutex>
#include <iostream>
#include <signal.h>

class InterruptHandler
{
public:
    static std::condition_variable s_condition;
    static std::mutex s_mutex;

    static void hookSIGINT()
    {
        signal(SIGINT, handleUserInterrupt);
    }

    static void handleUserInterrupt(int signal)
    {
        if (signal == SIGINT) {
            std::cout << "SIGINT trapped ..." << '\n';
            InterruptHandler::s_condition.notify_one();
        }
    }

    static void waitForUserInterrupt()
    {
        std::unique_lock<std::mutex> lock { InterruptHandler::s_mutex };
        InterruptHandler::s_condition.wait(lock);
        std::cout << "user has signaled to interrup program..." << '\n';
        lock.unlock();
    }
};
