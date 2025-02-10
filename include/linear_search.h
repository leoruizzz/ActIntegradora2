#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <vector>
#include <string>

class LinearSearch {
public:
    LinearSearch(const std::string& filename);
    int findNearestCentral(int newHouse) const;

private:
    std::vector<int> centralLocations;
    void readCentralsFromFile(const std::string& filename);
};

#endif

