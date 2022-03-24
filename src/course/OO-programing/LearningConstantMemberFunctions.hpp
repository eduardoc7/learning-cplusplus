#pragma once

/**
 * @brief Member functions qualified with const keyword
 * Both declaration and definition is qualified
 * Such functions cannot change value of any member variables
 * Useful for creating read only functions
 * Constant objects can invoke only constant member functions
 * */
class LearningConstantMemberFunctions {

    void constFunction() const {
        // used as functions that not modify the states of object
    }

    LearningConstantMemberFunctions() = default;
    ~LearningConstantMemberFunctions() = default;
};


