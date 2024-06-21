#ifndef FRACTAL_IMAGES_GENERATOR_BITMAPFILEHEADER_H
#define FRACTAL_IMAGES_GENERATOR_BITMAPFILEHEADER_H

#include <cstdint>

using namespace std;

#pragma pack(2)

// BitmapFileHeader contain the basic information about the BMP file
namespace btm{

    struct BitmapFileHeader{

        char header[2]{'B','M'}; // File identificator (always 'BM' for the BMP file
        int32_t fileSize; // File size in bytes
        int32_t reserved{0};
        int32_t dataOffset; // Show where pixels starts in the file (Sum of sizes of fileHeader and infoHeader)

    };

}

#endif //FRACTAL_IMAGES_GENERATOR_BITMAPFILEHEADER_H
