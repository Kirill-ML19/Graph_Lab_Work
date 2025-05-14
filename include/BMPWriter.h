#ifndef BMP_WRITER_H
#define BMP_WRITER_H

#include <string>
#include <vector>
#include <cstdint>

class BMPWriter {
public:
    static bool saveGrayscaleBMP(const std::string& filename,
                                  const std::vector<std::vector<std::uint8_t>>& image);
};

#endif 
