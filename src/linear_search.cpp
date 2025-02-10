#include "linear_search.h"
#include <fstream>
#include <cmath>

LinearSearch::LinearSearch(const std::string& filename) {
    readCentralsFromFile(filename);
}

int LinearSearch::findNearestCentral(int newHouse) const {
    int minDistance = std::numeric_limits<int>::max();
    int nearestCentral = -1;

    for (int central : centralLocations) {
        int distance = std::abs(central - newHouse);
        if (distance < minDistance) {
            minDistance = distance;
            nearestCentral = central;
        }
    }

    return nearestCentral;
}

void LinearSearch::readCentralsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    int location;
    while (file >> location) {
        centralLocations.push_back(location);
    }
}
