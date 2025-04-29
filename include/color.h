#ifndef COLOR_H
#define COLOR_H

#include <vec3.h>



using color = vec3;

inline void write_color(std::ostream& out, const color& pixel_color){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    auto rbyte = int(255.999 * r);
    auto gbyte = int(255.999 * g);
    auto bbyte = int(255.999 * b);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << "\n";
}



#endif