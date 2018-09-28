#ifndef _RAY_H_
#define _RAY_H_

#include "vec3.h"

class Ray {
    public:
        Ray();

        Ray(const Vec3& origin, const Vec3& direction, float ti = 0.0);

        Vec3 direction() const;

        Vec3 origin() const;

        Vec3 point_at_parameter(float t) const;

        float time() const;

    private:
        Vec3 o, dir;

        float _time;
};

#endif // _RAY_H_
