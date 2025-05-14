#include "Parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

Graph Parser::parse(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return Graph(); 
    }

    Graph graph;
    int vertices, edges;
    file >> vertices >> edges;
    graph.setVertexCount(vertices);

    int u, v;
    while (file >> u >> v) {
        graph.addEdge(u, v);
    }

    file.close();
    return graph;
}
