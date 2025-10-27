#pragma once

#include "../raylib/src/raylib.h"
Vector2 operator-(const Vector2& a, const Vector2& b); 
Vector2 operator+(const Vector2& a, const Vector2& b);
Vector2 operator*(const float& x, const Vector2& vector);
Vector2 operator*(const Vector2& vector, const float& x);
Vector2 operator/(const Vector2& vector, const float& x);

namespace Ex {
    float Distance(const Vector2& a, const Vector2& b);

    void setSize(Rectangle& rec, const Vector2& vec);
    void setPosition(Rectangle& rec, const Vector2& vec);
    
    Vector2 getSize(const Rectangle& rec);
    Vector2 getPostion(const Rectangle& rec);
}