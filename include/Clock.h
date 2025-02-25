#pragma once
#include <cstddef>
class Clock {
public:
    Clock();
    void        start();
    std::size_t getTime();
private:
    long        start_clock = 0;
};