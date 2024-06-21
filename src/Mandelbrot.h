#ifndef FRACTAL_IMAGES_GENERATOR_MANDELBROT_H
#define FRACTAL_IMAGES_GENERATOR_MANDELBROT_H


class Mandelbrot {

public:
    // Value for the amount of iterations, increase for better quality
    static const int MAX_ITERATIONS{1000};

public:
    // Function for a mandelbrot algorithm
    static int getIterations(double x, double y);

};


#endif //FRACTAL_IMAGES_GENERATOR_MANDELBROT_H
