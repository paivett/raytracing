#include "ray.h"


Ray::Ray() {

}

Ray::Ray(const Vec3& origin, const Vec3& direction) : o(origin), dir(direction) {

}

Vec3 Ray::direction() const { 
    return dir;
}


Vec3 Ray::origin() const { 
    return o;
}


Vec3 Ray::point_at_parameter(float t) { 
    return o + t * dir;
}
