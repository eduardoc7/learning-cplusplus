#pragma once

#include <iostream>
#include <vector>
#include <memory>

namespace algorithms {
    /**
     * @brief Concepts reference link: https://pt.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search
     * @param vec list of numbers
     * @param number_to_find target value to find
     * @return if number is found: return the index. if not: return 0
     */
    auto binarySearch(std::vector<int> vec, const int &number_to_find) -> std::uint64_t;

    /**
     * @brief A square matrix used to represent a finite graph
    */
    class GraphAdjacencyMatrix {
        std::uint64_t m_numVertices;
        bool **m_myMatrix;

    public:
        void showMatrix();
        void addVertice(const std::uint64_t &t_target, const std::uint64_t &t_source);
        void printMatrixLikePython();

        explicit GraphAdjacencyMatrix(const std::uint64_t &numVertices);
        GraphAdjacencyMatrix() = default;
        ~GraphAdjacencyMatrix();
    };
} // namespace algorithms
