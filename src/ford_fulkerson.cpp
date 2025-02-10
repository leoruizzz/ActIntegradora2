#include "ford_fulkerson.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>

FordFulkerson::FordFulkerson(const std::string& filename) : maxFlow(0) {
    readGraphFromFile(filename);
    flow = std::vector<std::vector<int>>(numVertices, std::vector<int>(numVertices, 0));
}

void FordFulkerson::run(int source, int sink) {
    calculateMaxFlow(source, sink);
}

void FordFulkerson::printMaxFlow() const {
    std::cout << "Maximum Flow: " << maxFlow << std::endl;
}

void FordFulkerson::readGraphFromFile(const std::string& filename) {
    std::ifstream file(filename);
    file >> numVertices;
    capacity.resize(numVertices, std::vector<int>(numVertices, 0));
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            file >> capacity[i][j];
        }
    }
}

bool FordFulkerson::bfs(std::vector<int>& parent, int source, int sink) {
    std::vector<bool> visited(numVertices, false);
    std::queue<int> queue;
    queue.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && capacity[u][v] - flow[u][v] > 0) {
                if (v == sink) {
                    parent[v] = u;
                    return true;
                }
                queue.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }

    return false;
}

void FordFulkerson::calculateMaxFlow(int source, int sink) {
    std::vector<int> parent(numVertices);
    int pathFlow;

    while (bfs(parent, source, sink)) {
        pathFlow = std::numeric_limits<int>::max();
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = std::min(pathFlow, capacity[u][v] - flow[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            flow[u][v] += pathFlow;
            flow[v][u] -= pathFlow;
        }

        maxFlow += pathFlow;
    }
}
