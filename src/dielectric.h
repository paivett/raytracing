#ifndef _DIELECTRIC_H_
#define _DIELECTRIC_H_

#include "material.h"

class Dielectric : public Material {
    public:
        Dielectric(float refraction_idx);
        
        virtual bool scatter(const Ray& ray_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const;
    
    private:
        float refraction_idx;
};

#endif // _DIELECTRIC_H_