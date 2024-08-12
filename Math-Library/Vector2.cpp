#include "Vector2.h"
#include <cmath>

using namespace Math;

Vector2::Vector2():
    x(0.f), y(0.f)
{
}

Vector2::Vector2(const float& x, const float& y):
    x(x), y(y)
{
}

Vector2::Vector2(const Vector2& vec):
    x(vec.x), y(vec.y)
{
}

Vector2& Vector2::operator=(const Vector2& rhs)
{
    x = rhs.x;
    y = rhs.y;
    return *this;
}

Vector2 Vector2::operator+(const Vector2& rhs) const
{
    return Vector2(x + rhs.x, y + rhs.y);
}

void Vector2::operator+=(const Vector2& rhs)
{
    x += rhs.x;
    y += rhs.y;
}

Vector2 Vector2::operator-(const Vector2& rhs) const
{
    return Vector2(x - rhs.x, y - rhs.y);
}

void Vector2::operator-=(const Vector2& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
}

Vector2 Vector2::operator*(const float& rhs) const
{
    return Vector2(x * rhs, y * rhs);
}

void Vector2::operator*=(const float& rhs)
{
    x *= rhs;
    y *= rhs;
}

Vector2 Vector2::operator/(const float& rhs) const
{
    return Vector2(x / rhs, y / rhs);
}

void Vector2::operator/=(const float& rhs)
{
    x /= rhs;
    y /= rhs;
}

float Math::Vector2::Length() const
{
    return std::sqrt(x * x + y * y);
}

float Math::Vector2::LengthSquared() const
{
    return x * x + y * y;
}
