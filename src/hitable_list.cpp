#include "hitable_list.h"

HitableList::HitableList() {

}

HitableList::HitableList(const std::list<std::shared_ptr<Hitable> >& hitables) : hitables(hitables) {

}

void HitableList::add(const std::shared_ptr<Hitable>& hitable) {
    hitables.push_back(hitable);
}

bool HitableList::hit(const Ray& ray, float t_min, float t_max, HitRecord& rec) const {
    HitRecord temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;
    for (auto& hitable : hitables) {
        if (hitable->hit(ray, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}