#ifndef RENDERER_H
#define RENDERER_H

#include "Graph.h"
#include <vector>
#include <utility> 
#include <cstdint>

class Renderer {
public:
    Renderer(int width, int height);
    void render(const Graph& graph);
    const std::vector<std::vector<std::uint8_t>>& getImage() const;

private:
    int width, height;
    std::vector<std::vector<std::uint8_t>> image; 

    void drawCircle(int cx, int cy, int radius, std::uint8_t color);
    void drawLine(int x0, int y0, int x1, int y1, std::uint8_t color);
    void setPixel(int x, int y, std::uint8_t color);
};

#endif // RENDERER_H
