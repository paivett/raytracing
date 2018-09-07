#include <iostream>
#include <cmath>
#include "ray.h"

#define CHANNEL_TO_INT(c)   (int(255.99 * c))

using namespace std;


float hit_sphere(const Vec3& center, float radius, const Ray& ray) {
    Vec3 oc = ray.origin() - center;
    float a = ray.direction() * ray.direction();
    float b = 2.0 * oc * ray.direction();
    float c = (oc * oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0.0) {
        return -1.0;
    }
    else {
        return (-b - sqrt(discriminant)) / (2.0 * a);
    }
}


Vec3 compute_color(const Ray& ray) {
    float t = hit_sphere(Vec3(0.0, 0.0, -1.0), 0.5, ray);

    if (t > 0.0) {
        Vec3 normal = (ray.point_at_parameter(t) - Vec3(0.0, 0.0, -1.0)).normalized();
        // Return the normal as if it was a normalized color
        return 0.5 * (normal + Vec3(1.0, 1.0, 1.0));
    }

    Vec3 unit_direction = ray.direction().normalized();
    t = 0.5 * (unit_direction.y + 1.0);
    return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
}


int main() {
    int nx = 400;
    int ny = 200;

    cout << "P3" << endl << nx << " " << ny << endl << "255" << endl;
    
    Vec3 lower_left_corner(-2.0, -1.0, -1.0);
    Vec3 horizontal(4.0, 0.0, 0.0);
    Vec3 vertical(0.0, 2.0, 0.0);
    Vec3 origin(0.0, 0.0, 0.0);

    for (int j = ny - 1; j >= 0; --j) {
        for (int i = 0; i < nx; ++i) {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            
            Ray ray(origin, lower_left_corner + u*horizontal + v*vertical);

            Vec3 color = compute_color(ray);

            cout << CHANNEL_TO_INT(color.x) << " " << CHANNEL_TO_INT(color.y) << " " << CHANNEL_TO_INT(color.z) << endl;
        }
    }
}
