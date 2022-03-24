#pragma once

#include <iostream>

/**
 * @brief Used to access the members atributes of a class
 * Is optional, because the compiler set that implicitly.
 * But, used in specific situations:
 * 1. To avoid shadow variables
 * 2. To call members functions
 */
class LearningThisPointer {
    int simple_value{0};
public:
    void AddSimpleValue(int simple_value) {
        this->simple_value = simple_value;
        Foo(*this);
    }

    void Foo(LearningThisPointer &Pointer);
};

