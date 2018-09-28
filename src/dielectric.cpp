#include "dielectric.h"
#include "random.h"
#include <cmath>

Dielectric::Dielectric(float refraction_idx) : refraction_idx(refraction_idx) {

}

bool refract(const Vec3& v, const Vec3& n, float ni_over_nt, Vec3& refracted) {
    Vec3 uv = v.normalized();
    float dt = uv * n;
    float discriminant = 1.0 - ni_over_nt * ni_over_nt * (1.0 - dt * dt);
    if (discriminant > 0.0) {
        refracted = ni_over_nt * (uv - n * dt) - n * sqrt(discriminant);
        return true;
    }
    else {
        return false;
    }
}

float schlick (float cosine, float refraction_idx) {
    float r0 = (1.0 - refraction_idx) / (1 + refraction_idx);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow(1 - cosine, 5.0);
}

bool Dielectric::scatter(const Ray& ray_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 reflected, refracted, outward_normal;
    float ni_over_nt, cosine, reflect_probability;
    attenuation = Vec3(1.0, 1.0, 1.0);
    
    if ((ray_in.direction() * rec.normal) > 0.0) {
        outward_normal = -rec.normal;
        ni_over_nt = refraction_idx;
        cosine = refraction_idx * (ray_in.direction() * rec.normal) / ray_in.direction().norm();
    }
    else {
        outward_normal = rec.normal;
        ni_over_nt = 1.0 / refraction_idx;
        cosine = -(ray_in.direction() * rec.normal) / ray_in.direction().norm();
    }

    if (refract(ray_in.direction(), outward_normal, ni_over_nt, refracted)) {
        reflect_probability = schlick(cosine, refraction_idx);
    }
    else {
        reflect_probability = 1.0;
    }

    if (random_number() < reflect_probability) {
        reflected = ray_in.direction().normalized().reflected(rec.normal);
        scattered = Ray(rec.p, reflected, ray_in.time());
    }
    else {
        scattered = Ray(rec.p, refracted, ray_in.time());
    }
    
    return true;
}