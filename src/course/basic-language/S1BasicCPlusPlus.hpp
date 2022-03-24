#pragma once

auto Add(const int *a, const int *b) -> int;

void AddVal(const int *a, const int *b, int *result);

void Swap(int *a, int *b);

void SwapByReference(int &a, int &b);

void print(int count, char ch);

class S1BasicCPlusPlus {
public:

    /**
     * @brief Pointers are references to another variables, that hold the memory.
     */
    static void pointers();

    /**
     * @brief A reference is an alternative name to a variable (an alias)
     * Is it created with & operator during declaration, when it is created it will always need an initializer.
     * Is not a new variable, that means no memory is allocated for a reference
     */
    static void references();

    static void references_vs_pointers();

    /**
     * @brief Allows iteration over arrays and containers
     * Doesn't need index variable
     * Each iteration returns an element of the container or the array
     * Can be used with any object that behaves like a range
     *
     * SyNTAX:
     * for (variable declaration : range) {
     *  statement;
     * }
     */
    static void range_based_for_loops();

    /**
     * @brief When 2 or more functions have a same name, but implementation different.
     * Arguments should differ in type and/or number.
     * This accepts pointers and references.
     * Return type is ignored.
     * For member functions, qualifiers participate in overload.
     * *this is resolved at compile time, static polymorphism.
     */
    static void function_over_loading();

    /**
     * @brief Request the compiler to replace the call with body function
     * This way, the overhead of the function call is avoided.
     *  Stack memory for arguments not required.
     *  No need to save the return address.
     *  ***Used with small body functions***
     */
    static void inline_function();

    static void function_pointers();

    /**
     * @brief Named declarative region used for declaring types
     * The types declared are not visible outside the namespace
     * Helps modularize code
     *
     */
    static void learning_namespaces();

    S1BasicCPlusPlus() = default; // simple constructor
    S1BasicCPlusPlus(const S1BasicCPlusPlus &) = default; // copy constructor
    S1BasicCPlusPlus(S1BasicCPlusPlus &&) = default; // move constructor
    auto operator=(const S1BasicCPlusPlus &) -> S1BasicCPlusPlus & = default; // copy assignment constructor
    auto operator=(S1BasicCPlusPlus &&) -> S1BasicCPlusPlus & = default; // move assignment operator
    ~S1BasicCPlusPlus() = default;
};
