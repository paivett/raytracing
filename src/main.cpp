#include <iostream>
#include <cmath>
#include <limits>
#include "random.h"
#include "camera.h"
#include "sphere.h"
#include "hitable_list.h"
#include "metal.h"
#include "lambertian.h"
#include "dielectric.h"

#define CHANNEL_TO_INT(c)   (int(255.99 * c))

using namespace std;

Vec3 compute_color(const Ray& ray, const HitableList& world, int recursion_depth) {
    HitRecord rec;
    
    if (world.hit(ray, 0.001, numeric_limits<float>::max(), rec)) {
        Ray scattered;
        Vec3 attenuation;
        if (recursion_depth < 50 && rec.material->scatter(ray, rec, attenuation, scattered)) {
            Vec3 color = compute_color(scattered, world, recursion_depth + 1);
            return Vec3(attenuation.x * color.x, attenuation.y * color.y, attenuation.z * color.z);
        }
        else {
            return Vec3(0.0, 0.0, 0.0);
        }
    }

    Vec3 unit_direction = ray.direction().normalized();
    float t = 0.5 * (unit_direction.y + 1.0);
    return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
}

int main() {
    int nx = 400;
    int ny = 200;
    int ns = 100; // Number of samples

    cout << "P3" << endl << nx << " " << ny << endl << "255" << endl;

    shared_ptr<Sphere> s1 = make_shared<Sphere>(Vec3(0.0, 0.0, -1.0), 0.5, make_shared<Lambertian>(Vec3(0.1, 0.2, 0.5)));
    shared_ptr<Sphere> s2 = make_shared<Sphere>(Vec3(0.0, -100.5, -1.0), 100.0, make_shared<Lambertian>(Vec3(0.8, 0.8, 0.0)));
    shared_ptr<Sphere> s3 = make_shared<Sphere>(Vec3(1.0, 0.0, -1.0), 0.5, make_shared<Metal>(Vec3(0.8, 0.6, 0.2), 0.1));
    shared_ptr<Sphere> s4 = make_shared<Sphere>(Vec3(-1.0, 0.0, -1.0), 0.5, make_shared<Dielectric>(1.5));
    shared_ptr<Sphere> s5 = make_shared<Sphere>(Vec3(-1.0, 0.0, -1.0), -0.45, make_shared<Dielectric>(1.5));

    HitableList world;
    world.add(s1);
    world.add(s2);
    world.add(s3);
    world.add(s4);
    world.add(s5);

    Camera cam(Vec3(-2.0, 2.0, 1.0), Vec3(0.0, 0.0, -1.0), Vec3(0.0, 1.0, 0.0), 90.0, float(nx) / float(ny));

    for (int j = ny - 1; j >= 0; --j) {
        for (int i = 0; i < nx; ++i) {
            Vec3 color(0.0, 0.0, 0.0);

            for (int s = 0; s < ns; ++s) {
                float u = float(i + random_number()) / float(nx);
                float v = float(j + random_number()) / float(ny);

                Ray ray = cam.get_ray(u, v);

                color += compute_color(ray, world, 0);
            }
            
            color /= float(ns);
            
            // gamma 2 correction
            color = Vec3(sqrt(color.x), sqrt(color.y), sqrt(color.z));

            cout << CHANNEL_TO_INT(color.x) << " " << CHANNEL_TO_INT(color.y) << " " << CHANNEL_TO_INT(color.z) << endl;
        }
    }
}
