#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <string>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    std::vector<Edge> edges;
};

class KruskalAlgorithm {
public:
    explicit KruskalAlgorithm(const std::string& filename);
    void run();
    void printResult() const;
    
    // Nuevas funciones
    int getTotalWeight() const;    // Calcula el peso total del MST
    int getNumberOfEdges() const;  // Devuelve el número de aristas en el MST

private:
    Graph graph;
    std::vector<Edge> mst;  
    void readGraphFromFile(const std::string& filename);
    int find(std::vector<int>& parent, int i);
    void unionSet(std::vector<int>& parent, std::vector<int>& rank, int x, int y);
    static bool edgeComp(const Edge& a, const Edge& b) { return a.weight < b.weight; }
};

#endif
