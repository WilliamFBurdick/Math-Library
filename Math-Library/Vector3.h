#pragma once

namespace Math
{
	class Vector3
	{
	private:
	public:
		float x, y, z;

		// Default constructor
		Vector3();
		// Parameter constructor
		Vector3(float x, float y, float z);

		~Vector3();
		// Copy constructor
		Vector3(const Vector3& v);

		// Operator overloads
		Vector3& operator=(const Vector3& rhs);
		Vector3 operator+(const Vector3& rhs) const;
		void operator+=(const Vector3& rhs);
		Vector3 operator-(const Vector3& rhs) const;
		void operator-=(const Vector3& rhs);
		Vector3 operator*(const float& rhs) const;
		void operator*=(const float& rhs);
		Vector3 operator/(const float& rhs) const;
		void operator/=(const float& rhs);

		// Dot and Cross products
		static float Dot(const Vector3& lhs, const Vector3& rhs);
		float Dot(const Vector3& rhs) const;
		static Vector3 Cross(const Vector3& lhs, const Vector3& rhs);
		Vector3 Cross(const Vector3& rhs) const;

		// Magnitude
		float Length() const;
		float LengthSquared() const;

		// Normalize
		void Normalize();
		Vector3 Normalized() const;
	};
}

