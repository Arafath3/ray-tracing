#ifndef HITTABLE_H
#define HITTABLE_H
#include "ray.h"

class hit_record {
    /* a bundle of info about a single ray-object intersection */
    public:
    point3 p;  // where ray hits
    vec3 normal; // surface noraml
    double t; // the distance along the ray where it hits
};


class hittable {
    public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};


#endif