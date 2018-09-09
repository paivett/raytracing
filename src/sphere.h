#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "hitable.h"

class Sphere : public Hitable {
    public:
        Sphere();

        Sphere(const Vec3& center, float radius);

        virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& rec) const;

    private:
        Vec3 center;
        float radius;
};

#endif // _SPHERE_H_