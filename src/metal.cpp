#include "metal.h"
#include "random.h"

Metal::Metal(const Vec3& albedo, float fuzziness) : albedo(albedo), fuzziness(fuzziness) {
    if (fuzziness > 1.0) {
        fuzziness = 1.0;
    }
}

bool Metal::scatter(const Ray& ray_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 reflected = ray_in.direction().normalized().reflected(rec.normal);
    scattered = Ray(rec.p, reflected + fuzziness * random_in_unit_sphere(), ray_in.time());
    attenuation = albedo;

    return (scattered.direction() * rec.normal) > 0.0;
}