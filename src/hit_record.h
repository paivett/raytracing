#ifndef _HIT_RECORD_H_
#define _HIT_RECORD_H_

#include <memory>
#include "vec3.h"

class Material;

struct HitRecord {
    float t;
    Vec3 p;
    Vec3 normal;
    std::shared_ptr<Material> material;
};

#endif // _HIT_RECORD_H