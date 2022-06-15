#pragma once

#include <memory>
#include <iostream>

/**
 * unique ptr is a class of template
 * Struct Person is used to be a type of std::unique template in this example
 * Important note: unique_ptr is unique XDXDXD - because its not be copied
 */
struct Person {
    std::string_view name;
    std::uint64_t age;

    Person(std::string_view name_input, const std::uint64_t &age_input)
    : name(name_input), age(age_input) { }

    ~Person() {
        std::cout << name << " goodbye!" << std::endl;
    }
};

static void DescribePerson(const Person &p) {
    std::cout << p.name << " is " << p.age << std::endl;
}

static void testUniquePointer() {
    // best way to use
    auto isabella = std::make_unique<Person>("Isabella", 18);

    // You can also pass any pointer to std::unique_ptr's constructor
    auto p = new Person("Nushi", 12);
    std::unique_ptr<Person> nushi(p);

    // unique_ptr can be used just like regular pointers
    // because of operator overloading
    DescribePerson(*isabella);
    DescribePerson(*nushi);
}
