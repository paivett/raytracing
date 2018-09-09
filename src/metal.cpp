#include "metal.h"
#include "random.h"

Metal::Metal(const Vec3& albedo) : albedo(albedo) {

}

bool Metal::scatter(const Ray& ray_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 reflected = ray_in.direction().normalized().reflected(rec.normal);
    scattered = Ray(rec.p, reflected);
    attenuation = albedo;

    return (scattered.direction() * rec.normal) > 0.0;
}