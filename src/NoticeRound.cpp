#include "../include/NoticeRound.h"
#include <raylib.h>
#include <string>

NoticeRound::NoticeRound(const int& index):Controller(index) {
    m_bound.width = n_width;
    m_bound.height = n_height;
    m_bound.y = (SCREEN_HEIGHT - n_height)/2;
}

bool NoticeRound::isOk() {
    if (m_is_ok) unloadAssets();
    return m_is_ok;
}
void NoticeRound::setAppleAndTime(const int& apple, const int& time) {
    m_apple = apple;
    m_time = time;
}
void NoticeRound::loadAssets() {
    APPLE_IMAGE = LoadTexture(apple_image);
    APPLE_IMAGE.width = 100;
    APPLE_IMAGE.height = 100;
}
void NoticeRound::unloadAssets() {
    UnloadTexture(APPLE_IMAGE);
}
void NoticeRound::draw() {
    DrawRectangleRounded(m_bound, n_roundness, notice_point_count, {100,200,100,200});
    Vector2 pos = {m_bound.x+m_bound.width/2 - 150, m_bound.y + m_bound.y/2};
    DrawTexture(APPLE_IMAGE, pos.x - APPLE_IMAGE.width/2, pos.y-APPLE_IMAGE.height/2, WHITE);
    DrawText(TextFormat("x%i | %is",m_apple, m_time), pos.x + APPLE_IMAGE.width/2, pos.y - 30, 80, BLACK);
}
void NoticeRound::setPosition(const float& x, const float& y) {
    m_bound.x = x;
    m_bound.y = y;
    motion.setRange(-m_bound.width, x);
}
void NoticeRound::run() {
    loadAssets();
    motion.setRange(-m_bound.width, 0);
    motion.setDuration(200);
    m_is_ok = false;
    motion.start();
    clock.start();
}
void NoticeRound::handle() {
    m_bound.x = motion.get();
    if (motion.get() == motion.getEndPoint()) {
        if (clock.getTime()<2000) {
            motion.setDuration(1000);
            motion.setRange(motion.getEndPoint(), motion.getEndPoint()+10);
            motion.start();
        } else if (clock.getTime()<3100) {
            motion.setDuration(200);
            motion.setRange(motion.getEndPoint(), m_bound.width);
            motion.start();
        } else m_is_ok = true;
    }
}
