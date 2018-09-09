#include <cmath>
#include "sphere.h"

Sphere::Sphere() {

}

Sphere::Sphere(const Vec3& center, float radius) : center(center), radius(radius) {
    
}

bool Sphere::hit(const Ray& ray, float t_min, float t_max, HitRecord& rec) const {
    Vec3 oc = ray.origin() - center;
    float a = ray.direction() * ray.direction();
    float b = oc * ray.direction();
    float c = (oc * oc) - radius * radius;
    float discriminant = b * b - a * c;
    if (discriminant > 0.0) {
        float sqrt_discriminant = sqrt(discriminant);
        float temp = (-b - sqrt_discriminant) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = ray.point_at_parameter(temp);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
        temp = (-b + sqrt_discriminant) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = ray.point_at_parameter(temp);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
    }
    return false;
}
