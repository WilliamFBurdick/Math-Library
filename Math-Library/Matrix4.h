#pragma once

namespace Math
{
	// Forward declarations
	class Vector3;
	class Quaternion;

	class Matrix4
	{
	public:
		float matrix[4][4];

		Matrix4();
		Matrix4(float value[4][4]);

		const float* GetFloatArray() const;

		// Operator overloads
		Matrix4 operator*(const Matrix4& rhs) const;
		void operator*=(const Matrix4& rhs);

		// Utilities
		void Invert();

		Vector3 GetTranslation() const;
		Vector3 GetXAxis() const;
		Vector3 GetYAxis() const;
		Vector3 GetZAxis() const;

		Vector3 GetScale() const;

		// Matrix creators
		static Matrix4 Scale(float xScale, float yScale, float zScale);
		static Matrix4 Scale(const Vector3& scaleVector);
		static Matrix4 RotationX(float theta);
		static Matrix4 RotationY(float theta);
		static Matrix4 RotationZ(float theta);
		static Matrix4 Rotation(const Quaternion& q);
		static Matrix4 Translation(const Vector3& translation);
		static Matrix4 LookAt(const Vector3& eyePosition, const Vector3& target, const Vector3& up);
		static Matrix4 Ortho(float width, float height, float near, float far);
		static Matrix4 PerspectiveFOV(float fovY, float width, float height, float near, float far);

		// Static constants
		static const Matrix4 Identity;
	};
}

