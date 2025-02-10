#ifndef TSP_H
#define TSP_H

#include <string>
#include <vector>
#include <limits>

class TSPAlgorithm {
public:
    explicit TSPAlgorithm(const std::string& filename);
    void run();
    void printResult() const;

private:
    std::vector<std::vector<int>> adjMatrix;
    std::vector<int> bestRoute;
    int bestCost;
    int numCities;

    void readMatrixFromFile(const std::string& filename);
    void nearestNeighbor(int start);
    int findClosestCity(int currentCity, std::vector<bool>& visited);
};

#endif
