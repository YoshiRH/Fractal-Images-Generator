#include "RGB.h"

RGB::RGB(double r, double g, double b)
:r(r), g(g), b(b) {

}

RGB RGB::operator-(const RGB &rhs) const {

    return {this->r - rhs.r, this->g - rhs.g, this->b - rhs.b};

}
