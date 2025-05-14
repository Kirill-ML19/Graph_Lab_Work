#include "Graph.h"

Graph::Graph(int numVertices)
    : vertexCount(numVertices) {}

void Graph::setVertexCount(int count) {
    vertexCount = count;
}

void Graph::addEdge(int u, int v) {
    adjacencyList[u].insert(v);
    adjacencyList[v].insert(u); 
}

const std::set<int>& Graph::getNeighbors(int vertex) const {
    static const std::set<int> empty;
    auto it = adjacencyList.find(vertex);
    return (it != adjacencyList.end()) ? it->second : empty;
}

int Graph::getVertexCount() const {
    return vertexCount;
}

const std::unordered_map<int, std::set<int>>& Graph::getAdjacencyList() const {
    return adjacencyList;
}
