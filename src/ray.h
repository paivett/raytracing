#ifndef _RAY_H_
#define _RAY_H_

#include "vec3.h"

class Ray {
    public:
        Ray() {};

        Ray(const Vec3& origin, const Vec3& direction) : o(origin), dir(direction) {};

        Vec3 direction() const { return dir; };

        Vec3 origin() const { return o; };

        Vec3 point_at_parameter(float t) { return o + t * dir; };

    private:
        Vec3 o, dir;
};

#endif
