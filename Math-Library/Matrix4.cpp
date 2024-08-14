#include "Math.h"

using namespace Math;

static float matrix4Identity[4][4] = {
    {1.f, 0.f, 0.f, 0.f},
    {0.f, 1.f, 0.f, 0.f},
    {0.f, 0.f, 1.f, 0.f},
    {0.f, 0.f, 0.f, 1.f}
};
const Matrix4 Matrix4::Identity(matrix4Identity);

Matrix4::Matrix4()
{
    *this = Matrix4::Identity;
}

Matrix4::Matrix4(float value[4][4])
{
    memcpy(matrix, value, 16 * sizeof(float));
}

const float* Matrix4::GetFloatArray() const
{
    return reinterpret_cast<const float*>(&matrix[0][0]);
}

Matrix4 Matrix4::operator*(const Matrix4& rhs) const
{
    Matrix4 retVal;
    // row 1
    retVal.matrix[0][0] = matrix[0][0] * rhs.matrix[0][0] + matrix[0][1] * rhs.matrix[1][0] * matrix[0][2] * rhs.matrix[2][0] + matrix[0][3] * rhs.matrix[3][0];
    retVal.matrix[0][1] = matrix[0][0] * rhs.matrix[0][1] + matrix[0][1] * rhs.matrix[1][1] * matrix[0][2] * rhs.matrix[2][1] + matrix[0][3] * rhs.matrix[3][1];
    retVal.matrix[0][2] = matrix[0][0] * rhs.matrix[0][2] + matrix[0][1] * rhs.matrix[1][2] * matrix[0][2] * rhs.matrix[2][2] + matrix[0][3] * rhs.matrix[3][2];
    retVal.matrix[0][3] = matrix[0][0] * rhs.matrix[0][3] + matrix[0][1] * rhs.matrix[1][3] * matrix[0][2] * rhs.matrix[2][3] + matrix[0][3] * rhs.matrix[3][3];
    // row 2
    retVal.matrix[1][0] = matrix[1][0] * rhs.matrix[0][0] + matrix[1][1] * rhs.matrix[1][0] * matrix[1][2] * rhs.matrix[2][0] + matrix[1][3] * rhs.matrix[3][0];
    retVal.matrix[1][1] = matrix[1][0] * rhs.matrix[0][1] + matrix[1][1] * rhs.matrix[1][1] * matrix[1][2] * rhs.matrix[2][1] + matrix[1][3] * rhs.matrix[3][1];
    retVal.matrix[1][2] = matrix[1][0] * rhs.matrix[0][2] + matrix[1][1] * rhs.matrix[1][2] * matrix[1][2] * rhs.matrix[2][2] + matrix[1][3] * rhs.matrix[3][2];
    retVal.matrix[1][3] = matrix[1][0] * rhs.matrix[0][3] + matrix[1][1] * rhs.matrix[1][3] * matrix[1][2] * rhs.matrix[2][3] + matrix[1][3] * rhs.matrix[3][3];
    // row 3
    retVal.matrix[2][0] = matrix[2][0] * rhs.matrix[0][0] + matrix[2][1] * rhs.matrix[1][0] * matrix[2][2] * rhs.matrix[2][0] + matrix[2][3] * rhs.matrix[3][0];
    retVal.matrix[2][0] = matrix[2][0] * rhs.matrix[0][1] + matrix[2][1] * rhs.matrix[1][1] * matrix[2][2] * rhs.matrix[2][1] + matrix[2][3] * rhs.matrix[3][1];
    retVal.matrix[2][0] = matrix[2][0] * rhs.matrix[0][2] + matrix[2][1] * rhs.matrix[1][2] * matrix[2][2] * rhs.matrix[2][2] + matrix[2][3] * rhs.matrix[3][2];
    retVal.matrix[2][0] = matrix[2][0] * rhs.matrix[0][3] + matrix[2][1] * rhs.matrix[1][3] * matrix[2][2] * rhs.matrix[2][3] + matrix[2][3] * rhs.matrix[3][3];
    // row 4
    retVal.matrix[3][0] = matrix[3][0] * rhs.matrix[0][0] + matrix[3][1] * rhs.matrix[1][0] * matrix[3][2] * rhs.matrix[2][0] + matrix[3][3] * rhs.matrix[3][0];
    retVal.matrix[3][0] = matrix[3][0] * rhs.matrix[0][1] + matrix[3][1] * rhs.matrix[1][1] * matrix[3][2] * rhs.matrix[2][1] + matrix[3][3] * rhs.matrix[3][1];
    retVal.matrix[3][0] = matrix[3][0] * rhs.matrix[0][2] + matrix[3][1] * rhs.matrix[1][2] * matrix[3][2] * rhs.matrix[2][2] + matrix[3][3] * rhs.matrix[3][2];
    retVal.matrix[3][0] = matrix[3][0] * rhs.matrix[0][3] + matrix[3][1] * rhs.matrix[1][3] * matrix[3][2] * rhs.matrix[2][3] + matrix[3][3] * rhs.matrix[3][3];

    return retVal;
}

void Matrix4::operator*=(const Matrix4& rhs)
{
    Matrix4 retVal;
    // row 1
    retVal.matrix[0][0] = matrix[0][0] * rhs.matrix[0][0] + matrix[0][1] * rhs.matrix[1][0] * matrix[0][2] * rhs.matrix[2][0] + matrix[0][3] * rhs.matrix[3][0];
    retVal.matrix[0][1] = matrix[0][0] * rhs.matrix[0][1] + matrix[0][1] * rhs.matrix[1][1] * matrix[0][2] * rhs.matrix[2][1] + matrix[0][3] * rhs.matrix[3][1];
    retVal.matrix[0][2] = matrix[0][0] * rhs.matrix[0][2] + matrix[0][1] * rhs.matrix[1][2] * matrix[0][2] * rhs.matrix[2][2] + matrix[0][3] * rhs.matrix[3][2];
    retVal.matrix[0][3] = matrix[0][0] * rhs.matrix[0][3] + matrix[0][1] * rhs.matrix[1][3] * matrix[0][2] * rhs.matrix[2][3] + matrix[0][3] * rhs.matrix[3][3];
    // row 2
    retVal.matrix[1][0] = matrix[1][0] * rhs.matrix[0][0] + matrix[1][1] * rhs.matrix[1][0] * matrix[1][2] * rhs.matrix[2][0] + matrix[1][3] * rhs.matrix[3][0];
    retVal.matrix[1][1] = matrix[1][0] * rhs.matrix[0][1] + matrix[1][1] * rhs.matrix[1][1] * matrix[1][2] * rhs.matrix[2][1] + matrix[1][3] * rhs.matrix[3][1];
    retVal.matrix[1][2] = matrix[1][0] * rhs.matrix[0][2] + matrix[1][1] * rhs.matrix[1][2] * matrix[1][2] * rhs.matrix[2][2] + matrix[1][3] * rhs.matrix[3][2];
    retVal.matrix[1][3] = matrix[1][0] * rhs.matrix[0][3] + matrix[1][1] * rhs.matrix[1][3] * matrix[1][2] * rhs.matrix[2][3] + matrix[1][3] * rhs.matrix[3][3];
    // row 3
    retVal.matrix[2][0] = matrix[2][0] * rhs.matrix[0][0] + matrix[2][1] * rhs.matrix[1][0] * matrix[2][2] * rhs.matrix[2][0] + matrix[2][3] * rhs.matrix[3][0];
    retVal.matrix[2][0] = matrix[2][0] * rhs.matrix[0][1] + matrix[2][1] * rhs.matrix[1][1] * matrix[2][2] * rhs.matrix[2][1] + matrix[2][3] * rhs.matrix[3][1];
    retVal.matrix[2][0] = matrix[2][0] * rhs.matrix[0][2] + matrix[2][1] * rhs.matrix[1][2] * matrix[2][2] * rhs.matrix[2][2] + matrix[2][3] * rhs.matrix[3][2];
    retVal.matrix[2][0] = matrix[2][0] * rhs.matrix[0][3] + matrix[2][1] * rhs.matrix[1][3] * matrix[2][2] * rhs.matrix[2][3] + matrix[2][3] * rhs.matrix[3][3];
    // row 4
    retVal.matrix[3][0] = matrix[3][0] * rhs.matrix[0][0] + matrix[3][1] * rhs.matrix[1][0] * matrix[3][2] * rhs.matrix[2][0] + matrix[3][3] * rhs.matrix[3][0];
    retVal.matrix[3][0] = matrix[3][0] * rhs.matrix[0][1] + matrix[3][1] * rhs.matrix[1][1] * matrix[3][2] * rhs.matrix[2][1] + matrix[3][3] * rhs.matrix[3][1];
    retVal.matrix[3][0] = matrix[3][0] * rhs.matrix[0][2] + matrix[3][1] * rhs.matrix[1][2] * matrix[3][2] * rhs.matrix[2][2] + matrix[3][3] * rhs.matrix[3][2];
    retVal.matrix[3][0] = matrix[3][0] * rhs.matrix[0][3] + matrix[3][1] * rhs.matrix[1][3] * matrix[3][2] * rhs.matrix[2][3] + matrix[3][3] * rhs.matrix[3][3];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = retVal.matrix[i][j];
}

void Math::Matrix4::Invert()
{
}

Vector3 Math::Matrix4::GetTranslation() const
{
    return Vector3(matrix[3][0], matrix[3][1], matrix[3][2]);
}

Vector3 Math::Matrix4::GetXAxis() const
{
    return Vector3(matrix[0][0], matrix[0][1], matrix[0][2]).Normalized();
}

Vector3 Math::Matrix4::GetYAxis() const
{
    return Vector3(matrix[1][0], matrix[1][1], matrix[1][2]).Normalized();
}

Vector3 Math::Matrix4::GetZAxis() const
{
    return Vector3(matrix[2][0], matrix[2][1], matrix[2][2]).Normalized();
}

Vector3 Math::Matrix4::GetScale() const
{
    Vector3 retVal;
    retVal.x = Vector3(matrix[0][0], matrix[0][1], matrix[0][2]).Length();
    retVal.y = Vector3(matrix[1][0], matrix[1][1], matrix[1][2]).Length();
    retVal.z = Vector3(matrix[2][0], matrix[2][1], matrix[2][2]).Length();
    return retVal;
}

Matrix4 Math::Matrix4::Scale(float xScale, float yScale, float zScale)
{
    float temp[4][4] = {
        {xScale, 0.f, 0.f, 0.f},
        {0.f, yScale, 0.f, 0.f},
        {0.f, 0.f, zScale, 0.f},
        {0.f, 0.f, 0.f, 1.f}
    };
    return Matrix4(temp);
}

Matrix4 Math::Matrix4::Scale(const Vector3& scaleVector)
{
    return Scale(scaleVector.x, scaleVector.y, scaleVector.z);
}

Matrix4 Math::Matrix4::RotationX(float theta)
{
    float temp[4][4] = {
        {1.f, 0.f, 0.f, 0.f},
        {0.f, Math::Cos(theta), Math::Sin(theta), 0.f},
        {0.f, -Math::Sin(theta), Math::Cos(theta), 0.f},
        {0.f, 0.f, 0.f, 1.f}
    };
    return Matrix4(temp);
}

Matrix4 Math::Matrix4::RotationY(float theta)
{
    float temp[4][4] = {
        {Math::Cos(theta), 0.f, -Math::Sin(theta), 0.f},
        {0.f, 1.f, 0.f, 0.f},
        {Math::Sin(theta), 0.f, Math::Cos(theta), 0.f},
        {0.f, 0.f, 0.f, 1.f}
    };
    return Matrix4(temp);
}

Matrix4 Math::Matrix4::RotationZ(float theta)
{
    float temp[4][4] = {
        {Math::Cos(theta), Math::Sin(theta), 0.f, 0.f},
        {-Math::Sin(theta), Math::Cos(theta), 0.f, 0.f},
        {0.f, 0.f, 1.f, 0.f},
        {0.f, 0.f, 0.f, 1.f}
    };
    return Matrix4(temp);
}

Matrix4 Math::Matrix4::Rotation(const Quaternion& q)
{
    return Matrix4();
}

Matrix4 Math::Matrix4::Translation(const Vector3& translation)
{
    float temp[4][4] = {
        {1.f, 0.f, 0.f, 0.f},
        {0.f, 1.f, 0.f, 0.f},
        {0.f, 0.f, 1.f, 0.f},
        {translation.x, translation.y, translation.z, 1.f}
    };
    return Matrix4(temp);
}

Matrix4 Math::Matrix4::LookAt(const Vector3& eyePosition, const Vector3& target, const Vector3& up)
{
    Vector3 zAxis = Vector3(target - eyePosition).Normalized();
    Vector3 xAxis = Vector3::Cross(up, zAxis).Normalized();
    Vector3 yAxis = Vector3::Cross(zAxis, xAxis).Normalized();
    Vector3 trans;
    trans.x = -Vector3::Dot(xAxis, eyePosition);
    trans.y = -Vector3::Dot(yAxis, eyePosition);
    trans.z = -Vector3::Dot(zAxis, eyePosition);

    float temp[4][4] = {
        {xAxis.x, yAxis.x, zAxis.x, 0.f},
        {xAxis.y, yAxis.y, zAxis.y, 0.f},
        {xAxis.z, yAxis.z, zAxis.z, 0.f},
        {trans.x, trans.y, trans.z, 1.f}
    };
    return Matrix4(temp);
}

Matrix4 Math::Matrix4::Ortho(float width, float height, float near, float far)
{
    float temp[4][4] = {
        {2.f / width, 0.f, 0.f, 0.f},
        {0.f, 2.f / height, 0.f, 0.f},
        {0.f, 0.f, 1.f / (far - near), 0.f},
        {0.f, 0.f, near / (near - far), 1.f}
    };
    return Matrix4(temp);
}

Matrix4 Math::Matrix4::PerspectiveFOV(float fovY, float width, float height, float near, float far)
{
    float yScale = Math::Cot(fovY / 2.f);
    float xScale = yScale * height / width;
    float temp[4][4] = {
        {xScale, 0.f, 0.f, 0.f},
        {0.f, yScale, 0.f, 0.f},
        {0.f, 0.f, far / (far - near), 1.f},
        {0.f, 0.f, -near * far / (far - near), 0.f}
    };
    return Matrix4(temp);
}
