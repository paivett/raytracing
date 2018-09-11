#include "camera.h"
#include "random.h"
#include <cmath>

Camera::Camera(const Vec3& look_from, const Vec3& look_at, const Vec3& vup, float vfov, float aspect, float aperture, float focus_dist) {
    lens_radius = aperture / 2.0;
    float theta = vfov * M_PI / 180.0;
    float half_height = tan(theta / 2.0);
    float half_width = aspect * half_height;

    origin = look_from;

    w = (look_from - look_at).normalized();
    u = (vup.cross(w)).normalized();
    v = w.cross(u);

    lower_left_corner = origin - half_width * focus_dist * u - half_height * focus_dist * v - focus_dist * w;
    horizontal = 2.0 * half_width * focus_dist * u;
    vertical = 2.0 * half_height * focus_dist * v;
}

Ray Camera::get_ray(float s, float t) {
    Vec3 rd = lens_radius * random_in_unit_disk();
    Vec3 offset = u * rd.x + v * rd.y;
    return Ray(origin + offset, lower_left_corner + s*horizontal + t*vertical - origin - offset);
}