cmake_minimum_required(VERSION 3.27)
project(Fractal_Images_Generator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Fractal_Images_Generator src/main.cpp
        src/BitmapInfoHeader.h
        src/BitmapFileHeader.h
        src/Bitmap.h
        src/Bitmap.cpp
        src/Mandelbrot.h
        src/Mandelbrot.cpp
        src/Zoom.h
        src/ZoomList.h
        src/ZoomList.cpp
        src/FractalCreator.h
        src/FractalCreator.cpp
        src/RGB.h
        src/RGB.cpp)
