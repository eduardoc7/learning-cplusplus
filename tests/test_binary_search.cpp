#include "../algorithms/binarySearch.hpp"
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
