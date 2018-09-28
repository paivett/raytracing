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

HitableList random_scene() {
    int n = 500;
    HitableList world;
    Vec3 v0(0, 0, 0);
    world.add(make_shared<Sphere>(Vec3(0.0, -1000.0, 0.0), 1000.0, make_shared<Lambertian>(Vec3(0.5, 0.5, 0.5)), v0));

    for (int a = -11; a < 11; ++a) {
        for (int b = -11; b < 11; ++b) {
            float choose_material = random_number();
            Vec3 center = Vec3(a + 0.9 * random_number(), 0.2, b + 0.9 * random_number());
            if ((center - Vec3(4.0, 0.2, 0.0)).norm() > 0.9) {
                Vec3 vel(0, 0.5 * random_number(), 0);
                if (choose_material < 0.8) {
                    Vec3 albedo = Vec3(random_number() * random_number(), random_number() * random_number(), random_number() * random_number());
                    world.add(make_shared<Sphere>(center, 0.2, make_shared<Lambertian>(albedo), vel));
                }
                else if (choose_material < 0.95) {
                    Vec3 albedo = 0.5 * (Vec3(random_number(), random_number(), random_number()) + Vec3(1.0, 1.0, 1.0));
                    float fuzziness = random_number() * 0.5;
                    world.add(make_shared<Sphere>(center, 0.2, make_shared<Metal>(albedo, fuzziness), v0));
                }
                else {
                    world.add(make_shared<Sphere>(center, 0.2, make_shared<Dielectric>(1.5), v0));                
                }
            }
        }
    }

    world.add(make_shared<Sphere>(Vec3(0.0, 1.0, 0.0), 1.0, make_shared<Dielectric>(1.5), v0));
    world.add(make_shared<Sphere>(Vec3(-4.0, 1.0, 0.0), 1.0, make_shared<Lambertian>(Vec3(0.4, 0.2, 0.1)), v0));
    world.add(make_shared<Sphere>(Vec3(4.0, 1.0, 0.0), 1.0, make_shared<Metal>(Vec3(0.7, 0.6, 0.5), 0.0), v0));

    return world;
}

int main() {
    int nx = 400;
    int ny = 200;
    int ns = 100; // Number of samples

    cout << "P3" << endl << nx << " " << ny << endl << "255" << endl;

    HitableList world = random_scene();
    
    Vec3 look_from(13.0, 2.0, 3.0);
    Vec3 look_at(0.0, 0.0, 0.0);
    float dist_to_focus = (look_from - look_at).norm();
    float aperture = 0.0;
    Camera cam(look_from, look_at, Vec3(0.0, 1.0, 0.0), 20.0, float(nx) / float(ny), aperture, dist_to_focus, 1.0);

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
