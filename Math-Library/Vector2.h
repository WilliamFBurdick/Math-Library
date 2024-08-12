#pragma once

namespace Math
{
	class Vector2
	{
	private:
	public:
		float x, y;

		// Constructors
		Vector2();
		Vector2(const float& x, const float& y);
		Vector2(const Vector2& vec);

		// Operator overloads
		Vector2& operator=(const Vector2& rhs);
		Vector2 operator+(const Vector2& rhs) const;
		void operator+=(const Vector2& rhs);
		Vector2 operator-(const Vector2& rhs) const;
		void operator-=(const Vector2& rhs);
		Vector2 operator*(const float& rhs) const;
		void operator*=(const float& rhs);
		Vector2 operator/(const float& rhs) const;
		void operator/=(const float& rhs);

		// Magnitude
		float Length() const;
		float LengthSquared() const;
	};
}

