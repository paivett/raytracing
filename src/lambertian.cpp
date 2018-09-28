#include "lambertian.h"
#include "random.h"

Lambertian::Lambertian(const Vec3& albedo) : albedo(albedo) {

}

bool Lambertian::scatter(const Ray& ray_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 target = rec.p + rec.normal + random_in_unit_sphere();
    scattered = Ray(rec.p, target - rec.p, ray_in.time());
    attenuation = albedo;

    return true;
}