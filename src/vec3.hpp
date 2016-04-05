#pragma once

#include <cmath>
#include <stdexcept>

namespace math {


    template<typename T>
    struct vec3 {
        T x;
        T y;
        T z;

        vec3() : x(0), y(0), z(0) { }

        vec3(const vec3<T> &&origin) {
            this->x = origin.x;
            this->y = origin.y;
            this->z = origin.z;
        }

        vec3(const vec3<T> &origin) {
            this->x = origin.x;
            this->y = origin.y;
            this->z = origin.z;
        }

        vec3(T x, T y, T z) : x(x), y(y), z(z) { }

        inline T r() const { return x; }

        inline T g() const { return y; }

        inline T b() const { return z; }

        inline const vec3 &operator+() const { return *this; }

//        inline vec3& operator=(vec3<T> other) {
//            if (this != &other) {
//                x = other.x;
//                y = other.y;
//                z = other.z;
//            }
//            return *this;
//        }
//


        inline vec3<T>& operator=(vec3<T> other){  // Notice the pass by value to get the copy.

            other.swap(*this);
            return *this;
        }

        inline void swap(vec3<T>& other) {
            std::swap(this->x, other.x);
            std::swap(this->y, other.y);
            std::swap(this->z, other.z);
        }

        inline vec3 operator-() const { return {-x, -y, -z}; }

        inline vec3 operator+(const vec3 &rhs) const {
            return {x + rhs.x, y + rhs.y, z + rhs.z};
        }

        inline vec3 operator-(const vec3 &rhs) const {
            return {x - rhs.x, y - rhs.y, z - rhs.z};
        }

        inline vec3 operator*(const vec3 &rhs) const {
            return {x * rhs.x, y * rhs.y, z * rhs.z};
        }

        inline vec3 operator/(const vec3 &rhs) const {
            return {x / rhs.x, y / rhs.y, z / rhs.z};
        }

        inline vec3 operator*(T t) const {
            return {t * x, t * y, t * z};
        }

        inline vec3 operator/ (T t) const {
            if (t == 0) throw std::runtime_error("Division by zero");
            return {x / t, y / t, z / t};
        }

        inline T dot(const vec3 &rhs) const {
            return x * rhs.x + y * rhs.y + z * rhs.z;
        }

        inline T sq_length() const {
            return x * x + y * y + z * z;
        }

        inline vec3 cross(const vec3 &rhs) {
            return {y * rhs.z - z * rhs.y,
                    z * rhs.x - x * rhs.z,
                    x * rhs.y - y * rhs.x};
        }

        inline T length() const {
            return sqrt(x*x + y*y + z*z);
        }

        inline T squared_length() const {
            return this->dot(*this);
        }


        inline vec3<T> normal() const {
            return *this / this->length();
        }

        inline void normalize(){
            this /= this->length();
        }
    };

    using vec3f = vec3<float>;
    using vec3i = vec3<int>;

    template<typename T>
    T dot(const vec3<T>& a, const vec3<T>& b){
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

}