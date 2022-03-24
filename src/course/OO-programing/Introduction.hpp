#pragma once

/**
 * @brief Objet Oriented Programming Introduction:
 * Uses objects as fundamental building blocks, rather algorithms
 * Program is created as a collection of objects
 * Every Object is an instance of some class
 * Allow simulates interactions of objects in real world systems
 * Allow representation of objets in a problem domain as software objects
 * Make code reusable, extensible and maintainable
 *
 * Basic principles to write OO programs:
 * 1. Abstraction
 * 2. Encapsulation
 * 3. Inheritance
 * 4. Polymorphism
 *
 * Patterns commonly used in POO: Design Patterns, SOLID, DRY
 */
class Introduction {
public:

    Introduction() = default; // default constructor
    Introduction(const Introduction &) = default; // copy constructor
    Introduction(Introduction &&) = default; // move constructor
    auto operator=(
            const Introduction &) -> Introduction & = default; // copy assignment constructor
    auto operator=(
            Introduction &&) -> Introduction & = default; // move assignment operator
    ~Introduction() = default; // destructor
};

