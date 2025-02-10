#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#include <vector>
#include <string>

class FordFulkerson {
public:
    FordFulkerson(const std::string& filename);
    void run(int source, int sink);
    void printMaxFlow() const;

private:
    std::vector<std::vector<int>> capacity;
    std::vector<std::vector<int>> flow;
    int numVertices;
    int maxFlow;

    void readGraphFromFile(const std::string& filename);
    bool bfs(std::vector<int>& parent, int source, int sink);
    void calculateMaxFlow(int source, int sink);
};

#endif
