#include "Parser.h"
#include "Graph.h"
#include "Renderer.h"
#include "BMPWriter.h"
#include <filesystem>
#include <iostream>
#include <vector>

namespace fs = std::filesystem;

int main() {
    std::string inputDir = "data";
    std::string outputDir = "images";

    if (!fs::exists(outputDir)) {
        fs::create_directory(outputDir);
    }

    for (const auto& entry : fs::directory_iterator(inputDir)) {
        if (entry.path().extension() == ".txt") {
            std::string inputPath = entry.path().string();
            std::string filename = entry.path().stem().string();
            std::string outputPath = outputDir + "/" + filename + ".bmp";

            std::cout << "Обработка: " << inputPath << "..." << std::endl;

            Graph graph = Parser::parse(inputPath);

            Renderer renderer(800, 800); 
            renderer.render(graph);
            const auto& image = renderer.getImage();

            bool success = BMPWriter::saveGrayscaleBMP(outputPath, image);

            if (success) {
                std::cout << "Сохранено изображение: " << outputPath << std::endl;
            } else {
                std::cerr << "Ошибка при сохранении: " << outputPath << std::endl;
            }
        }
    }

    return 0;
}
