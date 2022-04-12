#pragma once

/**
 * @brief A move constructor of class T is a non-template constructor whose first parameter is T&&, const T&&, volatile T&&, or const volatile T&&, and either there are no other parameters, or the rest of the parameters all have default values.
 * - Copy is implemented through copy constructor
 * - Copy of the object state is created
 * - Wasteful in case copy is created from a temporary
 * - Instead, the state can be moved from the source object
 * - Implemented through move semantics
 *
 * Why use move semantic?
 * R: When we have two object and we need to put state values in another, we should use move semantics.
 * Because instead of using normal copy like deep copy and allocate new resource to this object.
 * We use move semantics to use the same address used in old object.
 *
 * When use move semantic?
 * If an expression yields a temporary and that has to be copied in some other object,
 * then we should use move semantics
 *
 * How do we detect that temporary?
 * By default the copying would be performed by invoking the copy constructor and the temporary will be passed as an argument in that copy constructor
 * So, we can detect the temporary by implementing a constructor that accepts and RValue Referente.
 * */
class CopyAndMoveSemantics {

};


