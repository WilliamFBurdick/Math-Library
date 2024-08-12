#pragma once

#include "Matrix3.h"
#include "Vector3.h"

namespace Math
{
	const float Pi = 3.1415926535f;
	const float TwoPi = Pi * 2.0f;

	inline float ToRadians(float degrees)
	{
		return degrees * Pi / 180.0f;
	}

	inline float ToDegrees(float radians)
	{
		return radians * 180.0f / Pi;
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
}