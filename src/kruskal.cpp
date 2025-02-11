#include "kruskal.h"
#include <gtest/gtest.h>

class KruskalTest : public ::testing::Test {
protected:
    KruskalAlgorithm* kruskal;

    void SetUp() override {
        // Cargar el archivo de prueba y ejecutar el algoritmo
        kruskal = new KruskalAlgorithm("test_data/kruskal_test.txt");
        kruskal->run();
    }

    void TearDown() override {
        delete kruskal;  // Liberar memoria
    }
};

TEST_F(KruskalTest, TestTotalWeight) {
    int expectedWeight = 10; // Define el peso total esperado del MST para tu grafo de prueba
    ASSERT_EQ(kruskal->getTotalWeight(), expectedWeight);
}

TEST_F(KruskalTest, TestNumberOfEdges) {
    int expectedEdges = 3; // Define el número esperado de aristas en el MST
    ASSERT_EQ(kruskal->getNumberOfEdges(), expectedEdges);
}
