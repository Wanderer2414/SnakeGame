#include "../include/DynamicBox.h"
#include <cmath>
#include <ctime>
#include <raylib.h>

ExpandRRectangleBox::ExpandRRectangleBox(const int& index):Controller(index) {

}
Rectangle ExpandRRectangleBox::getBound() const  {
    return m_rec;
}
unsigned int ExpandRRectangleBox::getPointCount() const {
    return m_point_count;
}
float ExpandRRectangleBox::getRadius() const {
    return m_radius;
}
void ExpandRRectangleBox::setPointCount(const unsigned int& point_count) {
    m_point_count = point_count;
}
void ExpandRRectangleBox::setCenterPosition(const float& x, const float& y) {
    m_center_pos = {x , y};
    m_rec.x = m_center_pos.x - m_rec.width/2;
    m_rec.y = m_center_pos.y - m_rec.height/2;
}

void ExpandRRectangleBox::setPosition(const float& x, const float& y) {
    m_rec.x = x;
    m_rec.y = y;
    m_center_pos.x = m_rec.x + m_rec.width/2;
    m_center_pos.y = m_rec.y + getEndPoint()/2;
}
void ExpandRRectangleBox::setRadius(const float& radius) {
    m_radius = radius;
}
void ExpandRRectangleBox::setRange(const Vector2& start, const Vector2& end) {

}
void ExpandRRectangleBox::handle() {
    for (auto& i:children) i->handle();
}

void ExpandRRectangleBox::draw() {
    m_rec.height = get();
    m_rec.y = m_center_pos.y - m_rec.height/2;
    DrawRectangleRounded(m_rec, m_radius, m_point_count, color);
    if (ChildrenVisible && getEndPoint() == get())
        for (auto& i:children) i->draw();
};