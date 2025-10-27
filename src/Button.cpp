#include "../include/Button.h"
#include "../include/General.h"

Button::Button(const int& index):Controller(index) {
}

bool Button::isClicked() const {
    return (isHovered && IsMouseButtonReleased(MOUSE_BUTTON_LEFT));
}

Vector2 Button::getPosition() const {
    return {m_bound.x, m_bound.y};
}
Vector2 Button::getSize() const {
    return {m_bound.width, m_bound.height};
}
void Button::handle() {
    isHovered = CheckCollisionPointRec(GetMousePosition(), m_bound);
}

void Button::setPosition(const float& x, const float& y) {
    Ex::setPosition(m_bound, {x,y});
    Ex::setPosition(m_text_bound,Ex::getPostion(m_bound) + Ex::getSize(m_bound)/2 - Ex::getSize(m_text_bound)/2);
}
void Button::setText(const std::string& text) {
    m_text = text;
    m_text_bound.width = MeasureText(m_text.c_str(), font_size);
    m_text_bound.x = m_bound.x + m_bound.width/2 - m_text_bound.width/2;
}
void Button::setFontSize(const float& size) {
    font_size = size;
    m_text_bound.width = MeasureText(m_text.c_str(), font_size);
    m_text_bound.height = size;
    Ex::setPosition(m_text_bound, Ex::getPostion(m_bound) + Ex::getSize(m_bound)/2 - Ex::getSize(m_text_bound)/2);
}