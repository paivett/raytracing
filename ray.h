#ifndef _RAY_H_
#define _RAY_H_

#include "vec3.h"

class Ray {
    public:
        Ray() {};

        Ray(const vec3& origin, const vec3& direction) : o(origin), dir(direction) {};

        vec3 direction() const { return dir; };

        vec3 origin() const { return o; };

        vec3 point_at_parameter(float t) { return o + t * dir; };

    private:
        vec3 o, dir;
};

#endif
