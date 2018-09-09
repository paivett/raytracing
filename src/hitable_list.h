#ifndef _HITABLE_LIST_H_
#define _HITABLE_LIST_H_

#include <list>
#include "hitable.h"

class HitableList : public Hitable {
    public:
        HitableList();

        HitableList(const std::list<Hitable*>& hitables);

        void add(Hitable* hitable);

        virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& rec) const;

    private:
        std::list<Hitable*> hitables;
};

#endif // _HITABLE_LIST_H_