cmake_minimum_required(VERSION 3.10)
project(ActIntegradora2)

# Establecer C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluir directorios
include_directories(include)

# Archivos fuente principales
set(SOURCES
    src/main.cpp
    src/kruskal.cpp
    src/tsp.cpp
    src/ford_fulkerson.cpp
    src/linear_search.cpp
)

# Crear el ejecutable principal
add_executable(ActIntegradora2 ${SOURCES})

# Configuración de Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Habilitar pruebas
enable_testing()

# Crear el ejecutable para las pruebas
add_executable(algo_tests tests/test_kruskal.cpp tests/test_tsp.cpp tests/test_ford_fulkerson.cpp tests/test_linear_search.cpp ${SOURCES})

# Vincular Google Test
target_link_libraries(algo_tests gtest gtest_main)

# Registrar las pruebas para ejecución automática
include(GoogleTest)
gtest_discover_tests(algo_tests)
