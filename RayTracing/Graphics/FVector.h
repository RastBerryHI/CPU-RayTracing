#pragma once

#include <cstdlib>
#include <cmath>

namespace Graphics
{
    struct FVector
    {
        FVector() = delete;
        ~FVector();
        FVector(float e0, float e1, float e2) {e[0] = e0; e[1] = e1; e[2] = e2;}

        inline float X() const { return e[0]; }
        inline float Y() const { return e[1]; }
        inline float Z() const { return e[2]; }

        inline float R() const { return e[0]; }
        inline float G() const { return e[1]; }
        inline float B() const { return e[2]; }

        inline const FVector& operator+() const { return *this; }
        inline FVector operator-() const { return {-e[0], -e[1], -e[2]}; }
        inline FVector operator/(const FVector& v) const;
        inline FVector operator/(float t) const;
        inline FVector operator*(const FVector& v) const;
        inline FVector operator*(float t) const;
        inline float operator[](int i) const { return e[i]; }
        inline float& operator[](int i) { return e[i]; }
        
        inline FVector& operator+=(const FVector& v2);
        inline FVector& operator-=(const FVector& v2);
        inline FVector& operator*=(const FVector& v2);
        inline FVector& operator/=(const FVector& v2);
        inline FVector& operator*=(const float t);
        inline FVector& operator/=(const float t);

        inline float Length() { return sqrtf(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]); }
        inline float LengthSquared() const { return e[0]*e[0] + e[1]*e[1] + e[2]*e[2]; }
        inline FVector UnitVector(FVector v2);
        inline void MakeUnitVector();
    
    private:
        float* e = new float[3];
    };
}
