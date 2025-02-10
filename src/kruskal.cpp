#include "kruskal.h"
#include <fstream>
#include <algorithm>
#include <iostream>

KruskalAlgorithm::KruskalAlgorithm(const std::string& filename) {
    readGraphFromFile(filename);
}

void KruskalAlgorithm::run() {
    std::sort(graph.edges.begin(), graph.edges.end(), edgeComp);

    std::vector<int> parent(graph.V), rank(graph.V, 0);
    for (int i = 0; i < graph.V; ++i) {
        parent[i] = i;
    }

    for (auto& edge : graph.edges) {
        int x = find(parent, edge.src);
        int y = find(parent, edge.dest);
        if (x != y) {
            mst.push_back(edge);
            unionSet(parent, rank, x, y);
            if (mst.size() >= graph.V - 1) break;
        }
    }
}

void KruskalAlgorithm::printResult() const {
    for (const auto& edge : mst) {
        std::cout << edge.src << " - " << edge.dest << " : " << edge.weight << std::endl;
    }
}

void KruskalAlgorithm::readGraphFromFile(const std::string& filename) {
    std::ifstream file(filename);
    int u, v, w;
    file >> graph.V >> graph.E;
    while (file >> u >> v >> w) {
        graph.edges.push_back({u, v, w});
    }
}

int KruskalAlgorithm::find(std::vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void KruskalAlgorithm::unionSet(std::vector<int>& parent, std::vector<int>& rank, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}
