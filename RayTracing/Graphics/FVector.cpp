#include "FVector.h"

using namespace Graphics;

FVector::~FVector()
{
}

FVector FVector::operator/(const FVector& v) const
{
    return {e[0] / v.X(), e[1] / v.Y(), e[2] / v.Z()};
}

FVector FVector::operator/(float t) const
{
    return {e[0] / t, e[1] / t, e[2] / t};
}

FVector FVector::operator*(const FVector& v) const
{
    return {e[0] * v.X(), e[1] * v.Y(), e[2] * v.Z()};
}

FVector FVector::operator*(float t) const
{
    return {e[0] * t, e[1] * t, e[2] * t};
}

FVector& FVector::operator+=(const FVector& v2)
{
    e[0] += v2.X();
    e[1] += v2.Y();
    e[2] += v2.Z();
    return *this;
}

FVector& FVector::operator-=(const FVector& v2)
{
    e[0] -= v2.X();
    e[1] -= v2.Y();
    e[2] -= v2.Z();
    return *this;
}

FVector& FVector::operator*=(const FVector& v2)
{
    e[0] *= v2.X();
    e[1] *= v2.Y();
    e[2] *= v2.Z();
    return *this;
}

FVector& FVector::operator/=(const FVector& v2)
{
    e[0] /= v2.X();
    e[1] /= v2.Y();
    e[2] /= v2.Z();
    return *this;
}

FVector& FVector::operator*=(const float t)
{
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

FVector& FVector::operator/=(const float t)
{
    e[0] /= t;
    e[1] /= t;
    e[2] /= t;
    return *this;
}

FVector FVector::UnitVector(FVector v2)
{
    return v2 / v2.Length();
}

void FVector::MakeUnitVector()
{
    float k = 1.0f / sqrtf(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    e[0] += k; e[1] += k; e[2] += k;
}
