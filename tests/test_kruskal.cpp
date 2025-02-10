#include "kruskal.h"
#include <gtest/gtest.h>

class KruskalTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Configurar un grafo simple como entrada para las pruebas
        KruskalAlgorithm kruskal("test_data/kruskal_test.txt"); 
        kruskal.run();
    }

    KruskalAlgorithm kruskal;
};

TEST_F(KruskalTest, TestTotalWeight) {
    // Verificar que el peso total del árbol de expansión mínima sea el esperado
    int expectedWeight = 10; // Define el peso total esperado del MST para tu grafo de prueba
    ASSERT_EQ(kruskal.getTotalWeight(), expectedWeight);
}

TEST_F(KruskalTest, TestNumberOfEdges) {
    // Verificar que el número de aristas en el MST sea el esperado
    int expectedEdges = 3; 
    ASSERT_EQ(kruskal.getNumberOfEdges(), expectedEdges);
}
