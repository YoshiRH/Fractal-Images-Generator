#ifndef FRACTAL_IMAGES_GENERATOR_RGB_H
#define FRACTAL_IMAGES_GENERATOR_RGB_H


struct RGB {
    double r;
    double g;
    double b;

    RGB(double r, double g, double b);

    RGB operator -(const RGB &rhs) const;
};


#endif //FRACTAL_IMAGES_GENERATOR_RGB_H
