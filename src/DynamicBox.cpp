#include "../include/DynamicBox.h"
#include <cmath>
#include <ctime>

ExpandRRectangleBox::ExpandRRectangleBox(const int& index):Controller(index) {
    LinearMotion::setRange(0,1);
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
}

void ExpandRRectangleBox::setPosition(const float& x, const float& y) {
    m_rec.x = x;
    m_rec.y = y;
    m_center_pos = Ex::getPostion(m_rec) + Ex::getSize(m_rec)/2;
}
void ExpandRRectangleBox::setRadius(const float& radius) {
    m_radius = radius;
}
void ExpandRRectangleBox::setRange(const Vector2& start, const Vector2& end) {
    m_start = start;
    m_end = end;
    m_delta = end -start;
}
void ExpandRRectangleBox::handle() {
    Ex::setSize(m_rec, get()*m_delta + m_start);
    Ex::setPosition(m_rec, m_center_pos - Ex::getSize(m_rec)/2);
    for (auto& i:children) i->handle();
}

void ExpandRRectangleBox::draw() {
    DrawRectangleRounded(m_rec, m_radius, m_point_count, color);
    if (ChildrenVisible && getEndPoint() == get())
        for (auto& i:children) i->draw();
};