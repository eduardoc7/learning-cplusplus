#include <iostream>
#include "basic-language/S1BasicCPlusPlus.hpp"

auto Add(const int *a, const int *b) -> int {
    return *a + *b;
} // Add two numbers and return the sum

void AddVal(const int *a, const int *b, int *result) {
    *result = *a + *b;

    std::cout << "result is: " << *result << std::endl;
} // Add two numbers and return the sum through the third pointer argument

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} // Swap the value of two integers

/**
 * better than swap with pointers
 * @param a int value
 * @param b int value
 */
void SwapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
} // Swap the value of two integers


void Factorial(int *a, int *result);       //Generate the factorial of a number and return that through the second pointer argument

void print(int count, char ch) {
    for (int i = 0; i < count; ++i) {
        std::cout << ch << std::endl;
    }

}

/**
 * @brief When pointer is declared, but not initialized, it will contain a random access memory.
 * To access the value of variable through the pointer, is used asterisk operator (*). That can be called of Deference Operator;
 */
void S1BasicCPlusPlus::pointers() {
    int testing_address_operator = 1;

    std::cout << "my variable address: " << &testing_address_operator << std::endl;

        int *pointer_to_reference_variable_address = &testing_address_operator;

    void *pointer_to_use_with_different_kind_of_types = nullptr;
    std::cout << pointer_to_use_with_different_kind_of_types << std::endl;

    std::cout << "my pointer value that references: " << pointer_to_reference_variable_address << std::endl;

    int a = 2;
    int b = 4;

    Swap(&a, &b);
    std::swap(a, b);

    std::cout << "value (a): " << a << std::endl <<  "value (b): " << b << std::endl;
}

void S1BasicCPlusPlus::references() {
    // referent
    const int x = 10;

    // reference to a referent
    auto &ref = x;

    std::cout << ref << std::endl;

    // at that moment, both have the same value ^
    // both point the same address memory while running
}

void S1BasicCPlusPlus::references_vs_pointers() {

    /** @references:
     * always needs an initializer
     * initializer should be lvalue
     * cannot be nullptr
     * bound to its referent
     * no storage memory required, so has same address as that of referent
     *
     */

    /** @pointers:
     * initializer is optional
     * initializer need not be lvalue
     * can be nullptr
     * can point to other variables
     * has its own storage memory, so will have a different address
     * requires deference operator to access the value
    */
}

void S1BasicCPlusPlus::range_based_for_loops() {
    const int arr[] = { 1, 2, 3, 4, 5 };

    for(const auto &index : arr) {
        std::cout << index << std::endl;
    }

    // initialize lists
    for (const auto &index : {1, 2, 3}) {
        std::cout << index << std::endl;
    }

    // using pointer syntax
    const int *beg = std::begin(arr);
    const int *end = std::end(arr);

    while(beg != end) {
        std::cout << *beg << std::endl;
        ++beg;
    }

    // this is how range based for loop is internally implemented
    auto &&range = arr;
    auto begin = std::begin(range);
    auto end2 = std::end(range);

    for(;begin != end2; ++begin) {
        auto v = *begin;
        std::cout << v << std::endl;
    }
}

void S1BasicCPlusPlus::function_pointers() {
    void(*pfn) (const int, char) = print;
    (*pfn)(8, '$');
    pfn(5, '@');
    // the advantage is that we don't have to depend on the function name to invoke it
}
