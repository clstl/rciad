#pragma once

#include "ray.hpp"

namespace geometry {

    struct HitRecord {
        float t;
        math::vec3f p;
        math::vec3f normal;
    };

    struct Hitable {
        virtual bool hit(const math::Ray &r, float t_min, float t_max, HitRecord &rec) const = 0;
    };
}