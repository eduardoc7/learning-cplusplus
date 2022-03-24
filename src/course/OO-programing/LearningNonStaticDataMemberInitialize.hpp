#pragma once

#include <iostream>
#include <vector>

/**
 * @brief Convenient way of initialize class members with values during declaration.
 * Ensure the members are initialized with valid values
 * Can be used to initialize any type
 *
 *
 */
class LearningNonStaticDataMemberInitialize {
    std::uint64_t non_static_member {0};
    int array[5] {1 , 2, 3, 4, 5};
    std::vector<int> non_static_member_vector {3, 2, 1};
    char *non_static_member_null_pointer{};

    LearningNonStaticDataMemberInitialize() = default;
    ~LearningNonStaticDataMemberInitialize();
};



