#pragma once

#include <raylib.h>
#include <vector>
#include "Controller.h"
#include "LinearMotion.h"

class ExpandRRectangleBox:public Controller, public LinearMotion {
public:
    ExpandRRectangleBox(const int& index = -1);
    bool                ChildrenVisible = false;
    Rectangle           getBound() const;
    unsigned int        getPointCount() const;
    float               getRadius() const;
    void                setCenterPosition(const float& x, const float& y),
                        setPosition(const float &x, const float &y) override,
                        setRadius(const float& radius),
                        setPointCount(const unsigned int& point_count),
                        draw() override,
                        handle() override,
                        setRange(const Vector2& start, const Vector2& end);
    Color               color;
    std::vector<Controller*> children;
private:
    unsigned int    m_point_count = 30;
    Vector2         m_center_pos = {0, 0};
    Rectangle       m_rec;
    float           m_radius = 0;
    long            start_clock = 0;
};