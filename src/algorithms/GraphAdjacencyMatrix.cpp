#include <iostream>
#include "algorithms.hpp"

algorithms::GraphAdjacencyMatrix::GraphAdjacencyMatrix(const std::uint64_t &numVerticesInput)
        : numVertices(numVerticesInput) {
    // fill the matrix with 0
    std::vector<std::uint64_t> newVector;
    newVector.assign(numVerticesInput, 0);
    myMatrix.emplace_back(newVector);

    std::cout << "GraphAdjacencyMatrix" << std::endl;
}

void algorithms::GraphAdjacencyMatrix::showMatrix() {
    for(const auto &num : myMatrix) {
        std::cout << num.data() << std::endl;
    }
}
