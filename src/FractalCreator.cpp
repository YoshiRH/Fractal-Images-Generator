#include "FractalCreator.h"

#include <utility>
#include <iostream>
#include <assert.h>

#include "Mandelbrot.h"

// Function to pack other functions that we have to run to draw a fractal
void FractalCreator::run(string name) {

    calculateIteration();
    calculateTotalIterations();

    calculateRangeTotals();

    drawFractal();

    writeBitmap(std::move(name));

}

// Constructor
FractalCreator::FractalCreator(int width, int height)
:m_width(width), m_height(height), m_total(0),
m_histogram(new int [Mandelbrot::MAX_ITERATIONS] {0}),
m_fractal(new int [m_width * m_height] {0}),
m_bitmap(m_width, m_height),
m_zoomList(m_width, m_height) {

    m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));

}

void FractalCreator::calculateIteration() {

    for(int y=0; y < m_height; y++){

        for(int x=0; x < m_width; x++){

            pair<double, double> coords = m_zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIterations(coords.first, coords.second);

            m_fractal[y * m_width + x] = iterations;

            if(iterations != Mandelbrot::MAX_ITERATIONS){
                m_histogram[iterations]++;
            }

        }

    }

}

void FractalCreator::calculateTotalIterations() {

    for(int i=0; i<Mandelbrot::MAX_ITERATIONS; i++){

        m_total += m_histogram[i];

    }

}

void FractalCreator::calculateRangeTotals() {

    int rangeIndex{0};

    for(int i=0; i<Mandelbrot::MAX_ITERATIONS; i++){

        int pixels = m_histogram[i];

        if(i >= m_ranges[rangeIndex+1]){

            rangeIndex++;

        }

        m_rangesTotals[rangeIndex] += pixels;

    }

}

void FractalCreator::drawFractal() {

    for(int y=0; y < m_height; y++){

        for(int x=0; x < m_width; x++) {

            // Calculating the amount of iterations in certain pixel
            int iterations = m_fractal[y * m_width + x];

            // Checking in which range those iterations fit
            int range = getRange(iterations);
            int rangeTotal = m_rangesTotals[range];
            int rangeStart = m_ranges[range];

            // Selecting correct color based on the range of iterations
            RGB &startColor = m_colors[range];
            RGB &endColor = m_colors[range+1];

            RGB colorDiff = endColor-startColor;

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            if(iterations != Mandelbrot::MAX_ITERATIONS){

                int totalPixels = 0;

                for(int i=rangeStart; i<=iterations; i++){

                    totalPixels += m_histogram[i];

                }

                red = startColor.r + colorDiff.r*(double)totalPixels/rangeTotal;
                green = startColor.g + colorDiff.g*(double)totalPixels/rangeTotal;
                blue = startColor.b + colorDiff.b*(double)totalPixels/rangeTotal;

            }

            m_bitmap.setPixel(x, y, red, green, blue);

        }

    }

}

void FractalCreator::addRange(double rangeEnd, const RGB &rgb) {

    m_ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATIONS);
    m_colors.push_back(rgb);

    if(m_bGotFirstRange){

        m_rangesTotals.push_back(0);

    }
    else{

        m_bGotFirstRange = true;

    }

}

void FractalCreator::addZoom(const Zoom &zoom) {

    m_zoomList.add(zoom);

}

void FractalCreator::writeBitmap(string filename) {

    m_bitmap.write(filename);

}

// Function to check in which range the value of iterations fits.
int FractalCreator::getRange(int iterations) const {

    int range{0};

    // Checking in which range that value of iterations are.
    for(int i=1; i<m_ranges.size(); i++){

        range = i;

        // If the value of the interations fits into this certain range then break the loop.
        if(m_ranges[i] > iterations){
            break;
        }

    }

    range --;

    // Checking if those conditions are true (they must be to continue), otherwise we are out of range.
    assert(range > -1);
    assert(range < m_ranges.size());

    return range;

}

FractalCreator::~FractalCreator() {

}
