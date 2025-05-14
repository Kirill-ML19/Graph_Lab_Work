#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <set>

class Graph {
public:
    Graph(int numVertices = 0);
    
    void addEdge(int u, int v);
    const std::set<int>& getNeighbors(int vertex) const;
    int getVertexCount() const;
    const std::unordered_map<int, std::set<int>>& getAdjacencyList() const;

    void setVertexCount(int count);

private:
    int vertexCount;
    std::unordered_map<int, std::set<int>> adjacencyList;
};

#endif 
