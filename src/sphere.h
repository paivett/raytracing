#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <memory>
#include "hitable.h"
#include "material.h"

class Sphere : public Hitable {
    public:
        Sphere();

        Sphere(const Vec3& center, float radius, std::shared_ptr<Material> material, Vec3 speed);

        virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& rec) const;

        Vec3 center_at(float time) const;

    private:
        Vec3 center;
        float radius;
        std::shared_ptr<Material> material;
        Vec3 speed;
};

#endif // _SPHERE_H_