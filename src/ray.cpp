#include "ray.h"


Ray::Ray() {

}

Ray::Ray(const Vec3& origin, const Vec3& direction, float ti) : o(origin), dir(direction), _time(ti) {

}

Vec3 Ray::direction() const { 
    return dir;
}


Vec3 Ray::origin() const { 
    return o;
}


Vec3 Ray::point_at_parameter(float t) const { 
    return o + t * dir;
}

float Ray::time() const { 
    return _time;
}
