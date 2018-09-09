#ifndef _LAMBERTIAN_H_
#define _LAMBERTIAN_H_

#include "material.h"

class Lambertian : public Material {
    public:
        Lambertian(const Vec3& albedo);

        virtual bool scatter(const Ray& ray_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const;

    private:
        Vec3 albedo;
};


#endif // _LAMBERTIAN_H_