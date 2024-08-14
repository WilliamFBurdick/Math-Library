#pragma once

#include <cmath>
#include <memory>
#include <limits>

#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Quaternion.h"

namespace Math
{
	const float Pi = 3.1415926535f;
	const float TwoPi = Pi * 2.0f;
	const float PiOverTwo = Pi / 2.0f;
	const float Infinity = std::numeric_limits<float>::infinity();
	const float NegativeInfinity = -std::numeric_limits<float>::infinity();

	inline float ToRadians(float degrees)
	{
		return degrees * Pi / 180.0f;
	}

	inline float ToDegrees(float radians)
	{
		return radians * 180.0f / Pi;
	}

	inline bool NearZero(float value, float epsilon = 0.001f)
	{
		return (fabs(value) <= epsilon);
	}

	template <typename T>
	T Max(const T& rhs, const T& lhs)
	{
		return (rhs < lhs ? lhs : rhs);
	}

	template <typename T>
	T Min(const T& rhs, const T& lhs)
	{
		return (rhs < lhs ? rhs : lhs);
	}

	template <typename T>
	T Clamp(const T& value, const T& lower, const T& upper)
	{
		return Min(upper, Max(value, lower));
	}

	inline float Abs(float value)
	{
		return fabs(value);
	}

	inline float Cos(float angle)
	{
		return cosf(angle);
	}

	inline float Sin(float angle)
	{
		return sinf(angle);
	}

	inline float Tan(float angle)
	{
		return tanf(angle);
	}

	inline float Acos(float value)
	{
		return acosf(value);
	}

	inline float Atan2(float y, float x)
	{
		return atan2f(y, x);
	}

	inline float Cot(float angle)
	{
		return 1.0f / Tan(angle);
	}

	inline float Lerp(float val, float target, float step)
	{
		return val + step * (target - val);
	}

	inline float Sqrt(float value)
	{
		return sqrtf(value);
	}

	inline float Fmod(float numer, float denom)
	{
		return fmod(numer, denom);
	}
}