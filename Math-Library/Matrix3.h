#pragma once

namespace Math
{
	// Forward declaration
	class Vector2;

	class Matrix3
	{
	private:
	public:
		float matrix[3][3];

		// Constructors
		Matrix3();
		Matrix3(const Matrix3& inMatrix);
		Matrix3(float values[3][3]);
		Matrix3& operator=(const Matrix3& rhs);

		// Getters
		const float* GetFloatArray() const;

		// Debugging
		void Print();

		// Operator overloads
		Matrix3 operator+(const Matrix3& rhs) const;
		void operator+=(const Matrix3& rhs);
		Matrix3 operator*(const float& rhs) const;
		void operator*=(const float& rhs);
		Matrix3 operator*(const Matrix3& rhs) const;
		void operator*= (const Matrix3& rhs);

		// Matrix operations
		static Matrix3 Scale(float xScale, float yScale);
		static Matrix3 Scale(const Vector2& scaleVector);
		static Matrix3 Scale(float scale);
		static Matrix3 Rotation(float theta);
		static Matrix3 Translation(const Vector2& translation);

		// Constants
		static const Matrix3 Identity;
	};
}


