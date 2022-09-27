#include "../src/algorithms/algorithms.hpp"
#include <gtest/gtest.h>

// NOLINTNEXTLINE(hicpp-special-member-functions)
TEST(AlgorithmsTests, TestBinarySearch) {
    // Create a vector containing integers
    std::vector<int> my_vector = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
                                   41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    const int target_value = 73;

    auto result = algorithms::binarySearch(my_vector, target_value);

    ASSERT_EQ(20, result);
}

// NOLINTNEXTLINE(hicpp-special-member-functions)
TEST(AlgorithmsTests, TestGraphAdjacencyMatrix) {

    algorithms::GraphAdjacencyMatrix graph{4};

    graph.addVertice(0, 1);
    graph.addVertice(0, 2);
    graph.addVertice(1, 2);
    graph.addVertice(2, 0);
    graph.addVertice(2, 3);

    graph.showMatrix();
    graph.printMatrixLikePython();

    EXPECT_TRUE(true);
}

// NOLINTNEXTLINE(hicpp-special-member-functions)
TEST(AlgorithmsTests, TestGraphDijkstra) {
    algorithms::GraphDijkstra graph;

    graph.addVertice("A", {{"B", 7},
                           {"C", 8}});
    graph.addVertice("B", {{"A", 7},
                           {"F", 2}});

//    auto test = graph.findBetterPath("A", "B");
    std::cout << "return: " << std::endl;
    for (const auto &vertex: graph.findBetterPath("A", "B")) {
        std::cout << vertex << std::endl;
    }

//    graph.showGraph();

    EXPECT_TRUE(true);
}

