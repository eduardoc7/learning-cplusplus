#pragma once

/**
 * @brief
 * Some programming languages use the idea of l-values and r-values,
 * deriving from the typical mode of evaluation on the left and right hand side of an assignment
 * statement. An lvalue refers to an object that persists beyond a single expression.
 * An rvalue is a temporary value that does not persist beyond the expression that uses it.
 *
 * L-Value:
 *  - Has a name:
 *  - Essentially all variables are L-Value
 *  - Can be assigned values
 *  - Some expressions return l-value
 *  - Persists beyond the expressions
 *  - Reference to l-value (called l-value reference)
 *
 * R-Value:
 *  - Does not have a name: Is a temporary value
 *  - Cannot be a assigned values
 *  - Some expressions return r-value
 *  - Does not persist beyond the expression
 *  - Reference to r-value (called r-value reference)
 *
 *  Some functions return by reference. In that case, it will return an lvalue and
 *  functions that return by value will return rvalue
 */
class LearningRLValues {
public:
    void example() {
        /**
         * lvalues = x, y, z;
         * rvalues = 10, 2, 25;
         */
        int x = 10;
        int y = 2;
        int z = 25;

        /**
         * This expression will returns a r-value
         */
        int result = (x + y) * z;

        /**
         * This expression will returns a l-value
         */
         ++x = 6;
    }

    /**
     * @brief Returns R-value
     */
    int Add(int x, int y) {
        return x + y;
    }

    /*
     * @brief Returns L-value
     */
    int & Transform(int &x) {
        x *= x;
        return x;
    }
};
