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

		// Dot products
		static float Dot(const Vector2& lhs, const Vector2& rhs);
		float Dot(const Vector2& rhs) const;

		// Magnitude
		float Length() const;
		float LengthSquared() const;

		// Normalizing
		void Normalize();
		Vector2 Normalized() const;

		// Reflect
		static Vector2 Reflect(const Vector2& a, const Vector2& b);
		Vector2 Reflect(const Vector2& b);

		// Translate
		static Vector2 Transform(const Vector2& v, const class Matrix3& mat, float w = 1.f);
		Vector2 Transform(const class Matrix3& mat, float w = 1.f);

		// Constants
		static const Vector2 Zero;
		static const Vector2 UnitX;
		static const Vector2 UnitY;
		static const Vector2 NegUnitX;
		static const Vector2 NegUnitY;
	};
}

