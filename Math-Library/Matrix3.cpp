#include "Matrix3.h"
#include <cstdio>

using namespace Math;

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

void Math::Matrix3::Print()
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

Matrix3 Math::Matrix3::operator*(const Matrix3& rhs) const
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

Matrix3 Math::Matrix3::Identity()
{
	Matrix3 retVal;
	retVal.matrix[0][0] = 1;
	retVal.matrix[1][1] = 1;
	retVal.matrix[2][2] = 1;
	return retVal;
}

