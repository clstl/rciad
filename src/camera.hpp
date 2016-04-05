#pragma once

#include "ray.hpp"

struct Camera{


    Camera(double ratio){
        lower_left_corner={-2.0f, -1.0f, -1.0f};
        horizontal={4.0f, 0.0f, 0.0f};
        vertical={0.0f, float(ratio) * 4.0f, 0.0f};
        origin={0.0f, 0.0f, 0.0f};
    }

    math::vec3f origin;
    math::vec3f lower_left_corner;
    math::vec3f horizontal;
    math::vec3f vertical;

    math::Ray get_ray(float u, float v){
        return math::Ray{origin, lower_left_corner + horizontal * u + vertical * v};
    }
};