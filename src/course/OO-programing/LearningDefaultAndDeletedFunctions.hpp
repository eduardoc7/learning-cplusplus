#pragma once

/**
 * The keyword default is used to create an automatically default implementation to my constructor class,
 * without having to define it manually
 *
 * Used only those functions that can be synthesized by the compiler.
 * This way, that include's the destructor, copy constructor and assignment
 *
 * Delete keyword is used to tell the compiler not to synthesize the copy constructor.
 *
 *
 */
class LearningDefaultAndDeletedFunctions {
    int value {0};
public:
    LearningDefaultAndDeletedFunctions() = default;
    LearningDefaultAndDeletedFunctions(const LearningDefaultAndDeletedFunctions &) = delete;

    /**
     * @brief This function should not be able to receive float type as parameter
     * It's because we used a definition setValue with delete keyword
     *
     */
    void setValue(const int value_input) {
        value = value_input;
    }

    void setValue(float) = delete;
};
