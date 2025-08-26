cmake_minimum_required(VERSION 3.16)
project(RayTracer LANGUAGES CXX)

# Require C++17, no compiler-specific extensions
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Executable (add more .cpp files here if you split code later)
add_executable(raytracer
    src/main.cpp
)

# Tell the target where to find your headers in ./include
target_include_directories(raytracer PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Sensible warnings per compiler
target_compile_options(raytracer PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive- /EHsc>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra -Wpedantic>
)

# Default to Release if not specified (faster render)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()
