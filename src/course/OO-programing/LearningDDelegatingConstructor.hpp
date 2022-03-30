#pragma once

#include <iostream>

/**
 * @brief A delegating constructor can invoke another constructor
 * It is useful when you have multiple constructors in a class
 * and all the constructors have to do some common initialization
 *
 * Replacement for common initialization
 * This reduces duplicate initialization code in multiple constructors
 */
class LearningDDelegatingConstructor {
    int value1;
    int value2;
public:

    LearningDDelegatingConstructor();
    explicit LearningDDelegatingConstructor(int val1);
    LearningDDelegatingConstructor(int val1, int val2);

    ~LearningDDelegatingConstructor() = default;
};

LearningDDelegatingConstructor::LearningDDelegatingConstructor() : LearningDDelegatingConstructor(0) {
    std::cout << "default constructor" << std::endl;
}

LearningDDelegatingConstructor::LearningDDelegatingConstructor(int val1):LearningDDelegatingConstructor(val1, 0) {
    std::cout << "constructor parameterized  - explicit LearningDDelegatingConstructor(int val1);" << std::endl;
}

LearningDDelegatingConstructor::LearningDDelegatingConstructor(int val1, int val2) {
    std::cout << "constructor parameterized (int val1, int val2)" << std::endl;
    std::cout << "here, we have to do the initialization values to the class" << std::endl;
    value1 = val1;
    value2 = val2;

    /**
     * this way, we have initialization only in one constructor
     */
}


