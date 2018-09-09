#ifndef _METAL_H_
#define _METAL_H_

#include "material.h"

class Metal : public Material {
    public:
        Metal(const Vec3& albedo, float fuzziness);

        virtual bool scatter(const Ray& ray_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const;

    private:
        Vec3 albedo;
        float fuzziness;
};


#endif // _METAL_H_