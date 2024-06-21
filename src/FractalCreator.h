#ifndef FRACTAL_IMAGES_GENERATOR_FRACTALCREATOR_H
#define FRACTAL_IMAGES_GENERATOR_FRACTALCREATOR_H

#include <string>
#include <memory>
#include <vector>

#include "Zoom.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

class FractalCreator {
private:
    int m_width;
    int m_height;
    int m_total;

    bool m_bGotFirstRange{false};

    vector<int> m_ranges;
    vector<RGB> m_colors;
    vector<int> m_rangesTotals;

    unique_ptr<int[]> m_histogram;
    unique_ptr<int[]> m_fractal;
    Bitmap m_bitmap;
    ZoomList m_zoomList;

private:
    void calculateIteration();
    void calculateTotalIterations();
    void calculateRangeTotals();
    void drawFractal();
    void writeBitmap(string filename);
    int getRange(int iterations) const;

public:

    FractalCreator(int width, int height);
    void addRange(double rangeEnd, const RGB &rgb);
    void addZoom(const Zoom &zoom);
    void run(string name);

    virtual ~FractalCreator();

};


#endif //FRACTAL_IMAGES_GENERATOR_FRACTALCREATOR_H
