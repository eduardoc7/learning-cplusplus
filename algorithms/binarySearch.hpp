#pragma once

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

namespace algorithms {
    /**
     * @brief Concepts reference link: https://pt.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search
     * @param vec list of numbers
     * @param number_to_find target value to find
     * @return if number is found: return the index. if not: return 0
     */
    static auto binarySearch(std::vector<int> vec, const int &number_to_find) -> std::uint64_t {
        std::uint64_t min = 0;
        std::uint64_t max = (vec.size()) - 1;
        std::uint64_t current_index{0};

        // first step is: sort vector in ascending order
        std::sort(vec.begin(), vec.end());

        while (max >= min) {
            current_index = (max + min) / 2;

            if (vec[current_index] == number_to_find) {
                std::cout << "The number you're looking for is found! At: " << current_index << " index" << std::endl;

                return current_index;
            } else if (vec[current_index] < number_to_find) {
                min = current_index + 1;
            } else {
                max = current_index - 1;
            }
        }

        // if the number tried to find does not exist in vector
        return 0;
    }
} // namespace algorithms
