#ifndef SPHERE.H
#define SPEHERE.H

#include "hittable.h"
#include "vec3.h"
using namespace std;

class sphere: public hittable{
    public:
    sphere(const point3& center, double radius) : center(center), radius(fmax(0,radius)) {}

    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override{
        /* 
            refer to image calculating_sphere_part 1 and 2 + calculting_t
    
        */
        vec3 oc = center - r.origin();  // (C - P) or (C - Q), the vector from ray origin to sphere center
        auto a = dot(r.direction(), r.direction()); // d . d
        auto h = -2.0 * dot(r.direction(), oc); // −2d⋅(C−Q)
        auto c = dot(oc, oc) - radius * radius; // (C − Q) · (C − Q) − r²

        auto discriminant = h*h - 4*a*c; // b² - 4ac
    
        if(discriminant < 0){
        return -1.0;
        }
    
        auto sqrtd = sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (h - sqrtd) / a;   // first hit point on the sphere
        if (root <= ray_tmin || ray_tmax <= root) {   // checking if the hit point is below or above hit range value
            root = (h + sqrtd) / a; // exit point of the ray on sphere
            if (root <= ray_tmin || ray_tmax <= root)
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        rec.normal = (rec.p - center) / radius;

    }
    private:
    point3 center;
    double radius;
};


#endif