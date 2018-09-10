#include "camera.h"
#include <cmath>

Camera::Camera(const Vec3& look_from, const Vec3& look_at, const Vec3& vup, float vfov, float aspect) {
    Vec3 u, v, w;
    float theta = vfov * M_PI / 180.0;
    float half_height = tan(theta / 2.0);
    float half_width = aspect * half_height;

    origin = look_from;

    w = (look_from - look_at).normalized();
    u = (vup.cross(w)).normalized();
    v = w.cross(u);

    lower_left_corner = origin - half_width * u - half_height * v - w;
    horizontal = 2.0 * half_width * u;
    vertical = 2.0 * half_height * v;
}

Ray Camera::get_ray(float u, float v) {
    return Ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
}