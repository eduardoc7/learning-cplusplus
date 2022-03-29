#pragma once

/**
 * @brief Creates a copy of the object's state in another object
 * Synthesized by the compiler automatically
 * Default implementation copies values
 * Used-defined implementation required for pointer members
 *
 * To avoid a shallow copy, we use the user-defined copy constructor
 * .
 * If the class has pointer variables and has some dynamic memory allocations,
 * then it is a must to have a copy constructor.
 *
 * What the kind of classes will required user-defined copy constructor and assignment operator?
 * We have to follow the rule of 3:
 * It's says that if a user has implemented any of the following function, then it should probably:
 *
 * All should be defined if a user implements any of them:
 * 1. Destructor
 * 2. Copy Constructor
 * 3. Copy Assignment Operator
 *
 * Because the constructor of that class is acquiring some resource.
 * Maybe it's allocating some memory and a destructor is releasing that memory
 * Example:
 * 1. Destructor will free the resource
 * 2. Copy constructor will perform a deep copy
 * 3. Copy assigment operation will also perform a deep copy
 *
 */
class LearningCopyConstructor {
};

class Integer {
    int *member_pointer;

public:
    Integer() = default;

    explicit Integer(int value);

    ~Integer();

    int ShallowCopy() {
        /**
         * any change that we make to p1 or p2,
         * is going to reflect in all other pointers that hold the same address.
         * because this just copy the address
         *
         * this is called shallow copy
         */
        int *p1 = new int(5);
        int *p2 = p1;

        return 0;
    }

    int deepCopy() {
        /**
         * to perform the shallow copy, we can use the deep copy
         */

        int *p1 = new int(5);
        int *p2 = p1;

        int *p3 = new int(*p1);

        return 0;
    }

    int getValue() const;

    void setValue(int value);

};
