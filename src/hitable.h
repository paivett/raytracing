#ifndef _HITABLE_H_
#define _HITABLE_H_

#include "ray.h"
#include "hit_record.h"

class Hitable {
    public:
        virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& rec) const = 0;
};

#endif // _HITABLE_H_