#pragma once
#include "Clock.h"
#include <cstddef>
class LinearMotion {
public:
    LinearMotion();
    virtual bool    isRunning();
    virtual float   get(),
                    getEndPoint() const,
                    getStartPoint() const;
    virtual void    start(),
                    setDuration(const float& duration),
                    setDelay(const float& delay),
                    setRange(const float& start, const float& end);
private:
    float       m_start = 0,
                m_end = 0,
                m_delta = 0,
                m_cur = 0;
    long        m_start_clock   = 0,
                m_end_clock     = 0,
                m_duration_clock = 0,
                m_delay         = 0;
    Clock       clock;
};