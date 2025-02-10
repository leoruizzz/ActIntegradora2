#include "ford_fulkerson.h"
#include <gtest/gtest.h>

TEST(FordFulkersonTest, CalculateMaxFlow) {
    FordFulkerson ff("test_data/ford_fulkerson_test.txt");
    ff.run(0, 3); 
    int expectedFlow = 12; // Define el flujo máximo esperado 
    ASSERT_EQ(ff.getMaxFlow(), expectedFlow);
}
