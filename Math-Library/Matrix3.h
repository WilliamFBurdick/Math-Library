#pragma once

namespace Math
{
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
		static Matrix3 Identity();
		static Matrix3 Inverse(const Matrix3& value);
		static Matrix3 Transpose(const Matrix3& value);
	};
}


