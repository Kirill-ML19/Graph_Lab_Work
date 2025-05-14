#include "BMPWriter.h"
#include <fstream>
#include <iostream>

bool BMPWriter::saveGrayscaleBMP(const std::string& filename,
                                 const std::vector<std::vector<std::uint8_t>>& image) {
    int height = image.size();
    int width = image[0].size();
    int rowSize = (3 * width + 3) & ~3; 
    int imageSize = rowSize * height;

    unsigned char fileHeader[14] = {
        'B', 'M',                 
        0, 0, 0, 0,               
        0, 0, 0, 0,               
        54, 0, 0, 0               
    };

    unsigned char infoHeader[40] = {
        40, 0, 0, 0,              
        0, 0, 0, 0,              
        0, 0, 0, 0,               
        1, 0,                     
        24, 0,                    
        0, 0, 0, 0,              
        0, 0, 0, 0,               
        0, 0, 0, 0,               
        0, 0, 0, 0,               
        0, 0, 0, 0,              
        0, 0, 0, 0                
    };

    int fileSize = 54 + imageSize;
    fileHeader[2] = (unsigned char)(fileSize);
    fileHeader[3] = (unsigned char)(fileSize >> 8);
    fileHeader[4] = (unsigned char)(fileSize >> 16);
    fileHeader[5] = (unsigned char)(fileSize >> 24);

    infoHeader[4] = (unsigned char)(width);
    infoHeader[5] = (unsigned char)(width >> 8);
    infoHeader[6] = (unsigned char)(width >> 16);
    infoHeader[7] = (unsigned char)(width >> 24);

    infoHeader[8] = (unsigned char)(height);
    infoHeader[9] = (unsigned char)(height >> 8);
    infoHeader[10] = (unsigned char)(height >> 16);
    infoHeader[11] = (unsigned char)(height >> 24);

    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Ошибка: не удалось создать BMP-файл " << filename << std::endl;
        return false;
    }

    file.write(reinterpret_cast<char*>(fileHeader), 14);
    file.write(reinterpret_cast<char*>(infoHeader), 40);

    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            std::uint8_t gray = image[y][x];
            unsigned char pixel[3] = { gray, gray, gray };
            file.write(reinterpret_cast<char*>(pixel), 3);
        }
        int padding = rowSize - width * 3;
        for (int i = 0; i < padding; ++i) {
            unsigned char zero = 0;
            file.write(reinterpret_cast<char*>(&zero), 1);
        }
    }

    file.close();
    return true;
}
