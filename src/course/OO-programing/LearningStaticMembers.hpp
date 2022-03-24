#pragma once

/**
 * @brief Used with keyword 'static'
 * Not part of the object
 * Belong to the class
 * Only one copy exists
 * Cannot be initialize inside the class
 * Have to be defined outside the class for initialization
 * Static members functions:
 * don't receive 'this' pointer
 * Cannot acess non static members of the class
 */
class LearningStaticMembers {
    static int totalCount;

public:
    static void functionStaticMember() {}

    LearningStaticMembers() = default;
    ~LearningStaticMembers() = default;
};

