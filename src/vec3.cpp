#include "vec3.h"
#include <cmath>
#include <algorithm>

vec3::vec3() : x(.0), y(.0), z(.0) {
}

vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {
}

float vec3::sqr_norm() const {
    return x*x + y*y + z*z;
}

float vec3::norm() const {
    return sqrt(x*x + y*y + z*z);
}

vec3 vec3::operator-(const vec3& v) const {
    return vec3(x-v.x, y-v.y, z-v.z);
}

vec3& vec3::operator-=(const vec3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

vec3 vec3::operator+(const vec3& v) const {
    return vec3(x+v.x, y+v.y, z+v.z);
}

vec3& vec3::operator+=(const vec3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

vec3 vec3::operator-() const {
    return vec3(-x, -y, -z);
}

vec3 vec3::operator*(float lambda) const {
    return vec3(x*lambda, y*lambda, z*lambda);
}

vec3& vec3::operator*=(float lambda) {
    x *= lambda;
    y *= lambda;
    z *= lambda;
    return *this;
}

vec3 operator*(float lambda, const vec3 v) {
    return v * lambda;
}

float vec3::operator*(const vec3& v) const {
    return (x*v.x) + (y*v.y) + (z*v.z) ;
}

vec3 vec3::abs() const {
    return vec3(std::abs(x), std::abs(y), std::abs(z));
}

float vec3::max() const {
    return std::max(x, std::max(y, z));
}

float vec3::min() const {
    return std::min(x, std::min(y, z));
}

vec3 vec3::operator/(float lambda) const {
    return vec3(x/lambda, y/lambda, z/lambda);
}

vec3& vec3::operator/=(float lambda) {
    x /= lambda;
    y /= lambda;
    z /= lambda;
    return *this;
}

vec3 vec3::normalized() const {
    return (*this)/norm();
}

// Output to an ostream
std::ostream& operator<<(std::ostream& o, vec3 v) {
    o << v.x << ", " << v.y << ", " << v.z;
    return o;
}
