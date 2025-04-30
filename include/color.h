#ifndef COLOR_H
#define COLOR_H

#include <vec3.h>
#include "interval.h"



using color = vec3;

inline void write_color(std::ostream& out, const color& pixel_color){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Translate the [0,1] component values to the byte range [0,255].
    static const interval intensity(0.000, 0.999);
    auto rbyte = int(255.999 * intensity.clamp(r));
    auto gbyte = int(255.999 * intensity.clamp(g));
    auto bbyte = int(255.999 * intensity.clamp(b));

    out << rbyte << ' ' << gbyte << ' ' << bbyte << "\n";
}



#endif