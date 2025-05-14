#include "Renderer.h"
#include <cmath>
#include <iostream>
#include <algorithm>

Renderer::Renderer(int w, int h) : width(w), height(h) {
    image.resize(height, std::vector<std::uint8_t>(width, 255)); 
}

void Renderer::render(const Graph& graph) {
    int N = graph.getVertexCount();
    double centerX = width / 2.0;
    double centerY = height / 2.0;
    double radius = std::min(width, height) * 0.4;

    std::vector<std::pair<int, int>> positions(N + 1); 

    for (int i = 1; i <= N; ++i) {
        double angle = 2 * M_PI * i / N;
        int x = static_cast<int>(centerX + radius * cos(angle));
        int y = static_cast<int>(centerY + radius * sin(angle));
        positions[i] = {x, y};
    }

    for (const auto& [u, neighbors] : graph.getAdjacencyList()) {
        for (int v : neighbors) {
            if (u < v) 
                drawLine(positions[u].first, positions[u].second,
                         positions[v].first, positions[v].second, 0);
        }
    }

    for (int i = 1; i <= N; ++i) {
        drawCircle(positions[i].first, positions[i].second, 5, 0);
    }
}

const std::vector<std::vector<std::uint8_t>>& Renderer::getImage() const {
    return image;
}

void Renderer::setPixel(int x, int y, std::uint8_t color) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        image[y][x] = color;
    }
}

void Renderer::drawCircle(int cx, int cy, int r, std::uint8_t color) {
    for (int y = -r; y <= r; ++y) {
        for (int x = -r; x <= r; ++x) {
            if (x * x + y * y <= r * r) {
                setPixel(cx + x, cy + y, color);
            }
        }
    }
}

void Renderer::drawLine(int x0, int y0, int x1, int y1, std::uint8_t color) {
    int dx = std::abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -std::abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;

    while (true) {
        setPixel(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}
