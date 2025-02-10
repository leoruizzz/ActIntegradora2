#include "tsp.h"
#include <fstream>
#include <iostream>
#include <limits>

TSPAlgorithm::TSPAlgorithm(const std::string& filename) : bestCost(std::numeric_limits<int>::max()), numCities(0) {
    readMatrixFromFile(filename);
}

void TSPAlgorithm::run() {
    for (int start = 0; start < numCities; start++) {
        nearestNeighbor(start);
    }
}

void TSPAlgorithm::printResult() const {
    std::cout << "Best route cost: " << bestCost << std::endl;
    std::cout << "Best route: ";
    for (int city : bestRoute) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
}

void TSPAlgorithm::readMatrixFromFile(const std::string& filename) {
    std::ifstream file(filename);
    file >> numCities;
    adjMatrix.resize(numCities, std::vector<int>(numCities));
    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) {
            file >> adjMatrix[i][j];
        }
    }
}

void TSPAlgorithm::nearestNeighbor(int start) {
    std::vector<bool> visited(numCities, false);
    std::vector<int> route;
    int currentCity = start;
    int tourCost = 0;

    route.push_back(start);
    visited[start] = true;

    for (int i = 1; i < numCities; ++i) {
        int nextCity = findClosestCity(currentCity, visited);
        if (nextCity == -1) break;  
        tourCost += adjMatrix[currentCity][nextCity];
        currentCity = nextCity;
        visited[currentCity] = true;
        route.push_back(currentCity);
    }

    // Adding the return to the starting city
    tourCost += adjMatrix[currentCity][start];
    route.push_back(start);

    // Check if this route is better
    if (tourCost < bestCost) {
        bestCost = tourCost;
        bestRoute = route;
    }
}

int TSPAlgorithm::findClosestCity(int currentCity, std::vector<bool>& visited) {
    int minDistance = std::numeric_limits<int>::max();
    int closestCity = -1;
    for (int i = 0; i < numCities; ++i) {
        if (!visited[i] && adjMatrix[currentCity][i] < minDistance && i != currentCity) {
            minDistance = adjMatrix[currentCity][i];
            closestCity = i;
        }
    }
    return closestCity;
}
