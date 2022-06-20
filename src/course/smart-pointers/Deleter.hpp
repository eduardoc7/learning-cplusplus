#pragma once

/**
* @brief When the smart pointer destructor is called, that's invoke the deleter.
 * But, it's not invoke delete directly, instead they invoke a deleter.
 *
 * Deleter is a callback that releases the resource and both smart pointers.
*/

#include <iostream>
#include <memory>
#include <cstdlib>

/**
 * @brief A struct to be able a function object public globally.
 */
struct Free {
    void operator()(int *p) {
        free(p);
        std::cout << "pointer freed" << std::endl;
    }
};

static void testDeleterUniquePtr() {
    std::unique_ptr<int, Free> p {(int*) malloc(4), Free{}};
    *p = 100;

    std::cout << *p << std::endl;

//    free(p);
}

static void testDeleterSharedPtr() {
    // in shared_ptr we do not specify the type of deleter
    std::shared_ptr<int> p {(int*) malloc(4), Free{}};
    *p = 100;

    std::cout << *p << std::endl;

//    free(p);
}

