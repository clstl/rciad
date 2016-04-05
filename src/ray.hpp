#pragma once

#include "vec3.hpp"

namespace math {
    struct Ray {
        vec3f a, b;

        Ray() { }

        Ray(const vec3f &a, const vec3f &b)
                : a(a), b(b) { }

        vec3f origin() const { return a; }

        vec3f direction() const { return b; }

        vec3f point_at_parameter(float t) const {
            return a + (b * t);
        }

    };
}