#ifndef FRACTAL_IMAGES_GENERATOR_BITMAPINFOHEADER_H
#define FRACTAL_IMAGES_GENERATOR_BITMAPINFOHEADER_H

#include <cstdint>

using namespace std;

#pragma pack(2)

// BitmapInfoHeader contain information about the bitmap (size, colors etc..)
namespace btm{

    struct BitmapInfoHeader{

        int32_t headerSize{40}; // size of the header (sum of all below size values)
        int32_t width; // width of the bitmap
        int32_t height; // height of the bitmap
        int16_t planes{1};
        int16_t bitsPerPixel{24}; // 24 for RGB
        int32_t compression{0}; // no compression, all the pixel data is set right after the headers
        int32_t dataSize{0};
        int32_t horizontalResolution{2400};
        int32_t verticalResolution{2400};
        int32_t colors{0};
        int32_t importantColors{0};

    };


}



#endif //FRACTAL_IMAGES_GENERATOR_BITMAPINFOHEADER_H
