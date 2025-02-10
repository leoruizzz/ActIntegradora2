#include "kruskal.h"
#include "tsp.h"
#include "ford_fulkerson.h"
#include "linear_search.h"
#include <iostream>

int main() {
    try {
        KruskalAlgorithm kruskal("kruskal_input.txt");
        TSPAlgorithm tsp("tsp_input.txt");
        FordFulkerson ff("capacity_matrix.txt");
        LinearSearch ls("central_locations.txt");

        // Ejecuta y muestra resultados de Kruskal
        kruskal.run();
        kruskal.printResult();

        // Ejecuta y muestra resultados de TSP
        tsp.run();
        tsp.printResult();

        // Ejecuta y muestra resultados de Ford Fulkerson
        ff.run(0, 5);  // Suponiendo que el nodo inicial es 0 y el final es 5
        ff.printMaxFlow();

        // Encuentra la central más cercana para una nueva casa en la posición 7
        int nearestCentral = ls.findNearestCentral(7);
        std::cout << "La central más cercana a la nueva casa en la posición 7 es: " << nearestCentral << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
