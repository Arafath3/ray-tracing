#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.h"
#include "vec3.h"    


class hit_record {
     /* a bundle of info about a single ray-object intersection */
    public:
      point3 p; // where ray hits
      vec3 normal; // surface noraml
      double t; // the distance along the ray where it hits
      bool front_face;
  
      void set_face_normal(const ray& r, const vec3& outward_normal) {
          // Sets the hit record normal vector.
          // NOTE: the parameter `outward_normal` is assumed to have unit length.
  
          front_face = dot(r.direction(), outward_normal) < 0;
          normal = front_face ? outward_normal : -outward_normal;
      }
  };


class hittable {
    public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, interval ray_t  ,hit_record& rec) const = 0;
};


#endif