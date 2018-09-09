#include <iostream>
#include <cmath>
#include <random>
#include "camera.h"
#include "sphere.h"
#include "hitable_list.h"

#define CHANNEL_TO_INT(c)   (int(255.99 * c))

using namespace std;

Vec3 compute_color(const Ray& ray, const HitableList& world) {
    HitRecord rec;
    
    if (world.hit(ray, 0.0, MAXFLOAT, rec)) {
        return 0.5 * (rec.normal + Vec3(1.0, 1.0, 1.0));
    }

    Vec3 unit_direction = ray.direction().normalized();
    float t = 0.5 * (unit_direction.y + 1.0);
    return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
}


double random_number() {
    static default_random_engine generator;
    static uniform_real_distribution<double> distribution(0.0, 1.0);
    return distribution(generator);
}


int main() {
    int nx = 400;
    int ny = 200;
    int ns = 100; // Number of samples

    cout << "P3" << endl << nx << " " << ny << endl << "255" << endl;

    Sphere s1(Vec3(0.0, 0.0, -1.0), 0.5);
    Sphere s2(Vec3(0.0, -100.5, -1.0), 100.0);
    HitableList world;
    world.add(&s1);
    world.add(&s2);

    Camera cam;

    for (int j = ny - 1; j >= 0; --j) {
        for (int i = 0; i < nx; ++i) {
            Vec3 color(0.0, 0.0, 0.0);

            for (int s = 0; s < ns; ++s) {
                float u = float(i + random_number()) / float(nx);
                float v = float(j + random_number()) / float(ny);

                Ray ray = cam.get_ray(u, v);

                color += compute_color(ray, world);
            }
            
            color /= float(ns);

            cout << CHANNEL_TO_INT(color.x) << " " << CHANNEL_TO_INT(color.y) << " " << CHANNEL_TO_INT(color.z) << endl;
        }
    }
}
