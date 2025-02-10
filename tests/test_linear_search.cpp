#include "linear_search.h"
#include <gtest/gtest.h>

TEST(LinearSearchTest, FindNearestCentral) {
    LinearSearch ls("test_data/central_locations.txt");
    int houseLocation = 5; // La ubicación de la nueva casa
    int expectedCentral = 3; // La ubicación esperada de la central más cercana
    ASSERT_EQ(ls.findNearestCentral(houseLocation), expectedCentral);
}



