#pragma once

#include "hitable.hpp"

namespace geometry {

    class HitableList : public Hitable {

    public:
        Hitable **list;
        int list_size;
        HitableList() { }

        HitableList(Hitable **list, int list_size) : list(list), list_size(list_size) { }

        virtual bool hit(const math::Ray &r, float t_min, float t_max, HitRecord &rec) const override {
            HitRecord temp_rec;
            bool hit_anything = false;

            float closes_so_far = t_max;
            for(int i = 0; i < list_size; ++i){
                if(list[i]->hit(r, t_min, closes_so_far, temp_rec)){
                    hit_anything = true;
                    closes_so_far = temp_rec.t;
                    rec = temp_rec;
                }
            }
            return hit_anything;
        }


    };
}