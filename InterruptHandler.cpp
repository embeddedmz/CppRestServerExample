#include "InterruptHandler.h"

std::condition_variable InterruptHandler::s_condition;
std::mutex InterruptHandler::s_mutex;
