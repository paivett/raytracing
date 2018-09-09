#include "random.h"

double random_number() {
    static std::default_random_engine generator;
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    return distribution(generator);
}

Vec3 random_in_unit_sphere() {
    Vec3 p;
    do {
        p = 2.0 * Vec3(random_number(), random_number(), random_number()) - Vec3(1.0, 1.0, 1.0);
    } while(p.sqr_norm() >= 1.0);
    
    return p;
}