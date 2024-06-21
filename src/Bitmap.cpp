#include <fstream>
#include <iostream>

#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace btm;
using namespace std;

// Constructor
// It has to be width*height*3 because every pixel on BMP file is represent by 3 bytes (RGB)
Bitmap::Bitmap(int width, int height)
:m_height(height), m_width(width), m_pPixel(new uint8_t[width*height*3]{ }) {

}

// Function to save a bitmap to the file
bool Bitmap::write(const string& filename) {

    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + (m_width*m_height*3); // The size of the entire file
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader); // The distance from the beggining of the file to where the data (pixels) starts

    // Setting for infoHeader that contains information about the bitmap
    // Some values are already set in the .h file from the beggining
    infoHeader.width = m_width;
    infoHeader.height = m_height;

    // Creating a ofstream value with the passed filename as a parameter and
    // setting it as a binary file
    ofstream file;
    file.open(filename, ios::out|ios::binary);

    if(!file){
        return false;
    }

    // Writing data from file and info header to the file
    file.write((char *)&fileHeader, sizeof(fileHeader));
    file.write((char *)&infoHeader, sizeof(infoHeader));
    file.write((char *)m_pPixel.get(), m_width*m_height*3); // Saving pixels to file

    file.close();

    if(!file){
        return false;
    }

    return true;

}

// Function to set a color of the pixel on bitmap
void Bitmap::setPixel
(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

    // Pointer to the memory block that represents all the pixels on bitmap
    uint8_t *pPixel = m_pPixel.get();

    // Setting a value of that pointer to the pixel specified from parameters x and y;
    // (y*3)*m_width for the correct row on bitmap and +(x*3) for the column on that row.
    pPixel += (y*3)*m_width+(x*3);

    // Setting the color of single pixel
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
}

// Destructor
Bitmap::~Bitmap() {

}
