#pragma once

#include "hitable.hpp"

namespace geometry {

    struct Sphere : public Hitable {
        math::vec3f center;
        float radius;

        Sphere() { }

        Sphere(math::vec3f center, float r) : center(center), radius(r) {}

        virtual bool hit(const math::Ray &r, float t_min, float t_max, HitRecord &rec) const override {
            math::vec3f oc = r.origin() - center;
            float a = r.direction().sq_length();
            float b = math::dot(oc, r.direction());
            float c = oc.sq_length() - radius*radius;
            float discriminant = b*b - a*c;
            if(discriminant > 0){
                float temp = (-b - sqrt(discriminant)) / a;
                if(temp < t_max && temp > t_min){
                    rec.t = temp;
                    rec.p = r.point_at_parameter(rec.t);
                    rec.normal = (rec.p - center) / radius;
                    return true;
                }

                temp = (-b + sqrt(discriminant)) / a;
                if(temp < t_max && temp > t_min){
                    rec.t = temp;
                    rec.p = r.point_at_parameter(rec.t);
                    rec.normal = (rec.p - center) / radius;
                    return true;
                }
            }
            return false;
        }


    };

}