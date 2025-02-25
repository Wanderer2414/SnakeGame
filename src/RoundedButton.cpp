#include "../include/RoundedButton.h"
#include <raylib.h>

RoundedButton::RoundedButton(const int& index):Button(index) {
}

unsigned int RoundedButton::getPointCount() const {
    return m_point_count;
}

float RoundedButton::getRadius() const {
    return m_radius;
}

void RoundedButton::draw() {
    if (isHovered) {
        DrawRectangleRounded(m_bound, m_radius, m_point_count, hover_color);
        DrawText(m_text.c_str(), m_text_bound.x, m_text_bound.y, font_size, text_hover_color);
    } else {
        DrawRectangleRounded(m_bound, m_radius, m_point_count, normal_color);
        DrawText(m_text.c_str(), m_text_bound.x, m_text_bound.y, font_size, text_normal_color);
    }
}
void RoundedButton::setSize(const float& width, const float& height) {
    m_bound.width = width;
    m_bound.height = height;
    m_text_bound.x = m_bound.x + m_bound.width/2 - m_text_bound.width/2;
    m_text_bound.y = m_bound.y + m_bound.height/2 - m_text_bound.height/2;
}
void RoundedButton::setRadius(const float& radius) {
    m_radius = radius;
}