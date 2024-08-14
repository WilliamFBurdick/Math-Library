#pragma once

namespace Math
{
	class Vector3;

	class Quaternion
	{
	public:
		float x;
		float y;
		float z;
		float w;

		Quaternion();
		Quaternion(float x, float y, float z, float w);
		Quaternion(const Vector3& axis, float angle);

		void Set(float x, float y, float z, float w);
		void Conjugate();
		float LengthSquared() const;
		float Length() const;
		void Normalize();
	};
}

