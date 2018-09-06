#include <iostream>
#include "ray.h"

#define CHANNEL_TO_INT(c)   (int(255.99 * c))

using namespace std;


Vec3 compute_color(const Ray& ray) {
    Vec3 unit_direction = ray.direction().normalized();
    float t = 0.5 * (unit_direction.y + 1.0);
    return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
}


int main() {
    int nx = 200;
    int ny = 100;

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
