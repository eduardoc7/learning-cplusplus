#include <iostream>
#include <string>
#include <algorithm>
#include "algorithms.hpp"

algorithms::GraphAdjacencyMatrix::GraphAdjacencyMatrix(const std::uint64_t &t_numVertices)
        : m_numVertices(t_numVertices),
          m_myMatrix(new bool *[t_numVertices]),
          m_matrix(std::unique_ptr<std::vector<bool>(t_numVertices, 0)>) {
    std::cout << "GraphAdjacencyMatrix()" << std::endl;

    for (std::uint64_t i = 0; i < t_numVertices; i++) {
        m_myMatrix[i] = new bool[t_numVertices];
        for (std::uint64_t j = 0; j < t_numVertices; j++) {
            m_myMatrix[i][j] = false;
        }
    }
}

algorithms::GraphAdjacencyMatrix::~GraphAdjacencyMatrix() {
    std::cout << "~GraphAdjacencyMatrix()" << std::endl;
    for (std::uint64_t i = 0; i < m_numVertices; i++) {
        delete[] m_myMatrix[i];
    }
    delete[] m_myMatrix;
}

void algorithms::GraphAdjacencyMatrix::addVertice(const std::uint64_t &t_target, const std::uint64_t &t_source) {
    m_myMatrix[t_source][t_target] = true;
    m_myMatrix[t_target][t_source] = true;
}

void algorithms::GraphAdjacencyMatrix::showMatrix() {
    for (std::uint64_t i = 0; i < m_numVertices; i++) {
        std::cout << i << " : ";

        for (std::uint64_t j = 0; j < m_numVertices; j++) {
            std::cout << m_myMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void algorithms::GraphAdjacencyMatrix::printMatrixLikePython() {
    std::string result;

    result.append("[");
    for (std::uint64_t i = 0; i < m_numVertices; i++) {
        result.append("[");
        for (std::uint64_t j = 0; j < m_numVertices; j++) {
            result.append(std::to_string(m_myMatrix[i][j]));
        }
        result.append("],");
    }

    result.replace(result.length() - 1, result.length(), std::string(""));

    result.append("]");

    std::cout << result << std::endl;
}

