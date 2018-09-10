#ifndef _VEC3_H_
#define _VEC3_H_

#include <ostream>

struct Vec3 {
    Vec3();

    Vec3(float x, float y, float z);

    // Addition
    Vec3 operator+(const Vec3& v) const;
    Vec3& operator+=(const Vec3& v);

    // Sustraction
    Vec3 operator-(const Vec3& v) const;
    Vec3& operator-=(const Vec3& v);

    // Multiplication by scalar
    Vec3 operator*(float lambda) const;
    Vec3& operator*=(float lambda);

    // Division by a scalar
    Vec3 operator/(float lambda) const;
    Vec3& operator/=(float lambda);

    // Dot product
    float operator*(const Vec3& v) const;

    // Negation
    Vec3 operator-() const;

    // Returns the 2-norm
    float norm() const;

    // Returns the square of the 2-norm
    float sqr_norm() const;

    // Returns a new Vec3 with each coordinate
    // in absolute value
    Vec3 abs() const;

    // Returns max{x, y, z}
    float max() const;

    // Returns min{x, y, z}
    float min() const;

    // Returns a new vector normalized
    Vec3 normalized() const;

    // Returns a new vector reflected by the plane defined
    // by a given normal (should be a normal)
    Vec3 reflected(const Vec3& normal) const;

    Vec3 cross(const Vec3& v) const;

    // Actual components of the Vec3
    float x, y, z;
};

// Multiplication by a scalar
Vec3 operator*(float lambda, const Vec3 v);

// Output to an ostream
std::ostream& operator<<(std::ostream& o, Vec3 v);

#endif // _VEC3_H_
