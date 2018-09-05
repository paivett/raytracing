#ifndef VEC3_H
#define VEC3_H

#include <ostream>

struct vec3 {
    vec3();

    vec3(float x, float y, float z);

    // Addition
    vec3 operator+(const vec3& v) const;
    vec3& operator+=(const vec3& v);

    // Sustraction
    vec3 operator-(const vec3& v) const;
    vec3& operator-=(const vec3& v);

    // Multiplication by scalar
    vec3 operator*(float lambda) const;
    vec3& operator*=(float lambda);

    // Division by a scalar
    vec3 operator/(float lambda) const;
    vec3& operator/=(float lambda);

    // Dot product
    float operator*(const vec3& v) const;

    // Negation
    vec3 operator-() const;

    // Returns the 2-norm
    float norm() const;

    // Returns the square of the 2-norm
    float sqr_norm() const;

    // Returns a new vec3 with each coordinate
    // in absolute value
    vec3 abs() const;

    // Returns max{x, y, z}
    float max() const;

    // Returns min{x, y, z}
    float min() const;

    // Returns a new vector normalized
    vec3 normalized() const;

    // Actual components of the vec3
    float x, y, z;
};

// Multiplication by a scalar
vec3 operator*(float lambda, const vec3 v);

// Output to an ostream
std::ostream& operator<<(std::ostream& o, vec3 v);

#endif // VEC3_H
