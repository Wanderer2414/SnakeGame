#include "../include/Clock.h"
#include <chrono>

Clock::Clock() {
    start();
}

void Clock::start() {
    start_clock = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()).time_since_epoch().count();
}

size_t Clock::getTime() {
    return std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()).time_since_epoch().count() - start_clock;
}