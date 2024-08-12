#include "Vector3.h"
#include <cmath>

using namespace Math;

Vector3::Vector3():
	x(0.f), y(0.f), z(0.f)
{

}

Vector3::Vector3(float x, float y, float z)
	:x(x), y(y), z(z)
{
}

Vector3::~Vector3()
{
}

Vector3::Vector3(const Vector3& v):
	x(v.x), y(v.y), z(v.z)
{
}

Vector3& Vector3::operator=(const Vector3& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

Vector3 Vector3::operator+(const Vector3& rhs) const
{
	return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

void Vector3::operator+=(const Vector3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
}

Vector3 Vector3::operator-(const Vector3& rhs) const
{
	return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

void Vector3::operator-=(const Vector3& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
}

Vector3 Vector3::operator*(const float& rhs) const
{
	return Vector3(x * rhs, y * rhs, z * rhs);
}

void Vector3::operator*=(const float& rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
}

Vector3 Vector3::operator/(const float& rhs) const
{
	return Vector3(x / rhs, y / rhs, z / rhs);
}

void Vector3::operator/=(const float& rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
}

float Vector3::Dot(const Vector3& lhs, const Vector3& rhs)
{
	return	(lhs.x * rhs.x) + 
			(lhs.y * rhs.x) + 
			(lhs.z * rhs.z);
}

float Vector3::Dot(const Vector3& rhs) const
{
	return	(x * rhs.x) +
			(y * rhs.y) +
			(z * rhs.z);
}

Vector3 Vector3::Cross(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(	lhs.y * rhs.z - lhs.z * rhs.y,
					lhs.z * rhs.x - lhs.x * rhs.z,
					lhs.x * rhs.y - lhs.y * rhs.x);
}

Vector3 Vector3::Cross(const Vector3& rhs) const
{
	return Vector3(	y * rhs.z - z * rhs.y,
					z * rhs.x - x * rhs.z,
					x * rhs.y - y * rhs.x);
}

float Vector3::Length() const
{
	return std::sqrt(x * x + y * y + z * z);
}

float Vector3::LengthSquared() const
{
	return (x * x + y * y + z * z);
}

void Vector3::Normalize()
{
	float length = Length();
	if (length > 0)
	{
		x /= length;
		y /= length;
		z /= length;
	}
}

Vector3 Vector3::Normalized() const
{
	float length = Length();
	if (length > 0)
	{
		return Vector3(x / length, y / length, z / length);
	}
	else
	{
		return Vector3();
	}
}
