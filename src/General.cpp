#include "../include/General.h"
#include <cmath>
#include <raylib.h>

float Ex::Distance(const Vector2& a, const Vector2& b) {
    return std::sqrt(pow(a.x-b.x, 2) + pow(a.y - b.y,2));
}

void Ex::setSize(Rectangle& rec, const Vector2& vec) {
    rec.width = vec.x;
    rec.height = vec.y;
}
void Ex::setPosition(Rectangle& rec, const Vector2& vec) {
    rec.x = vec.x;
    rec.y = vec.y;
}

Vector2 Ex::getSize(const Rectangle& rec) {
    return {rec.width, rec.height};
}

Vector2 Ex::getPostion(const Rectangle& rec) {
    return {rec.x, rec.y};
}

Vector2 operator-(const Vector2& a, const Vector2& b) {
    return {a.x - b.x, a.y - b.y};
}
Vector2 operator+(const Vector2& a, const Vector2& b) {
    return {a.x + b.x, a.y + b.y};
}
Vector2 operator*(const float& x, const Vector2& vector) {
    return {x*vector.x, x*vector.y};
}
Vector2 operator*(const Vector2& vector, const float& x) {
    return {vector.x*x, vector.y*x};
}
Vector2 operator/(const Vector2& vector, const float& x) {
    return {vector.x / x, vector.y / x};
}
