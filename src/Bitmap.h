#ifndef FRACTAL_IMAGES_GENERATOR_BITMAP_H
#define FRACTAL_IMAGES_GENERATOR_BITMAP_H

#include <string>
#include <cstdint>
#include <memory>

using namespace std;

class Bitmap {

private:
    int m_width{0}; // Width of the bitmap
    int m_height{0}; // Height od the bitmap
    unique_ptr<uint8_t[]> m_pPixel{nullptr}; // Pointer to the pixel of bitmap

public:
    bool write(const string& filename); // Save bitmap to file
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue); // Set color of the pixel on bitmap


    Bitmap(int width, int height);
    virtual ~Bitmap();

};


#endif //FRACTAL_IMAGES_GENERATOR_BITMAP_H
