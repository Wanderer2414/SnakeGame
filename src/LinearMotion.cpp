#include "../include/LinearMotion.h"
#include <ctime>

LinearMotion::LinearMotion() {

}
float LinearMotion::get() {
    if (isRunning()) {
        m_cur = m_start + m_delta*1.0f*(clock.getTime() - m_start_clock)/m_duration_clock;
        return m_cur;
    } else if (clock.getTime() > m_end_clock) return m_end;
    else return m_start;
}
float LinearMotion::getStartPoint() const {
    return m_start;
}
float LinearMotion::getEndPoint() const {
    return m_end;
}
void LinearMotion::start() {
    m_start_clock = clock.getTime() + m_delay;
    m_end_clock = m_start_clock + m_duration_clock;
}
void LinearMotion::setDuration(const float& duration) {
    m_duration_clock = duration;
}
void LinearMotion::setDelay(const float& delay) {
    m_delay = delay;
}
void LinearMotion::setRange(const float& start, const float& end) {
    m_cur = m_start = start;
    m_end = end;
    m_delta = end-start;
}
bool LinearMotion::isRunning() {
    if (clock.getTime() >= m_start_clock && clock.getTime() <= m_end_clock) return true;
    return false;
}