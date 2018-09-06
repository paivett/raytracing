#include "vec3.h"
#include <cmath>
#include <algorithm>

Vec3::Vec3() : x(.0), y(.0), z(.0) {
}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {
}

float Vec3::sqr_norm() const {
    return x*x + y*y + z*z;
}

float Vec3::norm() const {
    return sqrt(x*x + y*y + z*z);
}

Vec3 Vec3::operator-(const Vec3& v) const {
    return Vec3(x-v.x, y-v.y, z-v.z);
}

Vec3& Vec3::operator-=(const Vec3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vec3 Vec3::operator+(const Vec3& v) const {
    return Vec3(x+v.x, y+v.y, z+v.z);
}

Vec3& Vec3::operator+=(const Vec3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vec3 Vec3::operator-() const {
    return Vec3(-x, -y, -z);
}

Vec3 Vec3::operator*(float lambda) const {
    return Vec3(x*lambda, y*lambda, z*lambda);
}

Vec3& Vec3::operator*=(float lambda) {
    x *= lambda;
    y *= lambda;
    z *= lambda;
    return *this;
}

Vec3 operator*(float lambda, const Vec3 v) {
    return v * lambda;
}

float Vec3::operator*(const Vec3& v) const {
    return (x*v.x) + (y*v.y) + (z*v.z) ;
}

Vec3 Vec3::abs() const {
    return Vec3(std::abs(x), std::abs(y), std::abs(z));
}

float Vec3::max() const {
    return std::max(x, std::max(y, z));
}

float Vec3::min() const {
    return std::min(x, std::min(y, z));
}

Vec3 Vec3::operator/(float lambda) const {
    return Vec3(x/lambda, y/lambda, z/lambda);
}

Vec3& Vec3::operator/=(float lambda) {
    x /= lambda;
    y /= lambda;
    z /= lambda;
    return *this;
}

Vec3 Vec3::normalized() const {
    return (*this)/norm();
}

// Output to an ostream
std::ostream& operator<<(std::ostream& o, Vec3 v) {
    o << v.x << ", " << v.y << ", " << v.z;
    return o;
}
