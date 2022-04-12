#pragma once

/**
 * R-Value References:
 *  - Have been introduced in c++11 to implement move semantics
 *  - A reference created to a temporary
 *  - And it represents a temporary value
 *  - Its created with this operator: &&. This is called as the R-Value reference operator
 *  - Rvalues references cannot bind to lvalues
 *  - They will always bind to temporaries
 *  - An lvalue references always bind to lvalues
 *
 *
 */
class RLValuesReferences {
public:
    void example() {
        /**
         * 10 is temporary and r1 is a rvalue reference to it
         */
        int &&r1 = 10;

        /**
         * we cannot bind rvalues to lvalues:
         * int x = 0;
         * int &&r2 = x;
         *
         * and we cannot bind an lvalue reference may bind to a temporary:
         * int &ref = 10;
         *
         * its just work if the reference is a const:
         * const int &ref2 = 3;
         *
         */


    }

};
