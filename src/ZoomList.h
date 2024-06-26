#include <vector>
#include <utility>

#include "Zoom.h"

#ifndef FRACTAL_IMAGES_GENERATOR_ZOOMLIST_H
#define FRACTAL_IMAGES_GENERATOR_ZOOMLIST_H

using namespace std;

class ZoomList {
private:
    double m_xCenter{0.0};
    double m_yCenter{0.0};
    double m_scale{1.0};

    int m_width{0};
    int m_height{0};
    vector<Zoom> zooms;

public:
    ZoomList(int width, int height);
    void add(const Zoom& zoom);
    pair<double, double> doZoom(int x, int y);
};


#endif //FRACTAL_IMAGES_GENERATOR_ZOOMLIST_H
