#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "hit_record.h"
#include "ray.h"

class Material {
    public:
        virtual bool scatter(const Ray& ray_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const = 0;
};

#endif // _MATERIAL_H_