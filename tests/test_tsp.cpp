#include "tsp.h"
#include <gtest/gtest.h>

TEST(TSPTest, CalculateShortestPath) {
    TSPAlgorithm tsp("test_data/tsp_test.txt");
    tsp.run();
    int expectedCost = 25; // Define el costo esperado de la ruta más corta basada en tus datos de prueba
    ASSERT_EQ(tsp.getBestCost(), expectedCost);
}
