#include "Math.h"
#include <cstdio>

using namespace Math;

static float matrix3Identity[3][3] = {
	{1.f, 0.f, 0.f},
	{0.f, 1.f, 0.f},
	{0.f, 0.f, 1.f}
};
const Matrix3 Matrix3::Identity(matrix3Identity);

Matrix3::Matrix3()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] = 0.0f;
}

Matrix3::Matrix3(const Matrix3& inMatrix)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] = inMatrix.matrix[i][j];
}

Matrix3::Matrix3(float values[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] = values[i][j];
}

void Matrix3::Print()
{
	printf("[%f,%f,%f\n%f,%f,%f\n%f,%f,%f]\n", 
		matrix[0][0], matrix[0][1], matrix[0][2], 
		matrix[1][0], matrix[1][1], matrix[1][2], 
		matrix[2][0], matrix[2][1], matrix[2][2]);
}

Matrix3 Matrix3::operator+(const Matrix3& rhs) const
{
	Matrix3 retVal;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			retVal.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];

	return retVal;
}

void Matrix3::operator+=(const Matrix3& rhs)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] += rhs.matrix[i][j];
}

Matrix3 Matrix3::operator*(const float& rhs) const
{
	Matrix3 retVal;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			retVal.matrix[i][j] = matrix[i][j] * rhs;

	return retVal;
}

void Matrix3::operator*=(const float& rhs)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] *= rhs;
}

Matrix3 Matrix3::operator*(const Matrix3& rhs) const
{
	Matrix3 retVal;
	// Row 1
	retVal.matrix[0][0] = matrix[0][0] * rhs.matrix[0][0] + matrix[0][1] * rhs.matrix[1][0] + matrix[0][2] * rhs.matrix[2][0];
	retVal.matrix[0][1] = matrix[0][0] * rhs.matrix[0][1] + matrix[0][1] * rhs.matrix[1][1] + matrix[0][2] * rhs.matrix[2][1];
	retVal.matrix[0][2] = matrix[0][0] * rhs.matrix[0][2] + matrix[0][1] * rhs.matrix[1][2] + matrix[0][2] * rhs.matrix[2][2];
	// Row 2
	retVal.matrix[1][0] = matrix[1][0] * rhs.matrix[0][0] + matrix[1][1] * rhs.matrix[1][0] + matrix[1][2] * rhs.matrix[2][0];
	retVal.matrix[1][1] = matrix[1][0] * rhs.matrix[0][1] + matrix[1][1] * rhs.matrix[1][1] + matrix[1][2] * rhs.matrix[2][1];
	retVal.matrix[1][2] = matrix[1][0] * rhs.matrix[0][2] + matrix[1][1] * rhs.matrix[1][2] + matrix[1][2] * rhs.matrix[2][2];
	// Row 3
	retVal.matrix[2][0] = matrix[2][0] * rhs.matrix[0][0] + matrix[2][1] * rhs.matrix[1][0] + matrix[2][2] * rhs.matrix[2][0];
	retVal.matrix[2][1] = matrix[2][0] * rhs.matrix[0][1] + matrix[2][1] * rhs.matrix[1][1] + matrix[2][2] * rhs.matrix[2][1];
	retVal.matrix[2][2] = matrix[2][0] * rhs.matrix[0][2] + matrix[2][1] * rhs.matrix[1][2] + matrix[2][2] * rhs.matrix[2][2];

	return retVal;
}

void Matrix3::operator*=(const Matrix3& rhs)
{
	Matrix3 retVal;
	// Row 1
	retVal.matrix[0][0] = matrix[0][0] * rhs.matrix[0][0] + matrix[0][1] * rhs.matrix[1][0] + matrix[0][2] * rhs.matrix[2][0];
	retVal.matrix[0][1] = matrix[0][0] * rhs.matrix[0][1] + matrix[0][1] * rhs.matrix[1][1] + matrix[0][2] * rhs.matrix[2][1];
	retVal.matrix[0][2] = matrix[0][0] * rhs.matrix[0][2] + matrix[0][1] * rhs.matrix[1][2] + matrix[0][2] * rhs.matrix[2][2];
	// Row 2
	retVal.matrix[1][0] = matrix[1][0] * rhs.matrix[0][0] + matrix[1][1] * rhs.matrix[1][0] + matrix[1][2] * rhs.matrix[2][0];
	retVal.matrix[1][1] = matrix[1][0] * rhs.matrix[0][1] + matrix[1][1] * rhs.matrix[1][1] + matrix[1][2] * rhs.matrix[2][1];
	retVal.matrix[1][2] = matrix[1][0] * rhs.matrix[0][2] + matrix[1][1] * rhs.matrix[1][2] + matrix[1][2] * rhs.matrix[2][2];
	// Row 3
	retVal.matrix[2][0] = matrix[2][0] * rhs.matrix[0][0] + matrix[2][1] * rhs.matrix[1][0] + matrix[2][2] * rhs.matrix[2][0];
	retVal.matrix[2][1] = matrix[2][0] * rhs.matrix[0][1] + matrix[2][1] * rhs.matrix[1][1] + matrix[2][2] * rhs.matrix[2][1];
	retVal.matrix[2][2] = matrix[2][0] * rhs.matrix[0][2] + matrix[2][1] * rhs.matrix[1][2] + matrix[2][2] * rhs.matrix[2][2];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] = retVal.matrix[i][j];
}

Matrix3 Matrix3::Scale(float xScale, float yScale)
{
	float temp[3][3] = {
		{xScale, 0.f, 0.f},
		{0.f, yScale, 0.f},
		{0.f, 0.f, 1.f}
	};
	return Matrix3(temp);
}

Matrix3 Matrix3::Scale(const Vector2& scaleVector)
{
	return Scale(scaleVector.x, scaleVector.y);
}

Matrix3 Matrix3::Scale(float scale)
{
	return Scale(scale, scale);
}

Matrix3 Matrix3::Rotation(float theta)
{
	float temp[3][3] = {
		{Math::Cos(theta), Math::Sin(theta), 0.f},
		{-Math::Sin(theta), Math::Cos(theta), 0.f},
		{0.f, 0.f, 1.f}
	};
	return Matrix3(temp);
}

Matrix3 Matrix3::Translation(const Vector2& translation)
{
	float temp[3][3] = {
		{1.f, 0.f, 0.f},
		{0.f, 1.f, 0.f},
		{translation.x, translation.y, 1.f}
	};
	return Matrix3(temp);
}

