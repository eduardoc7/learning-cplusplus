#pragma once
#include <iostream>

struct Point {
    int x;
    int y;
};


/**
 * @brief Create a user defined type thorough keyword struct
 * Similar to class
 * Default acess is public
 * Usually used to represent simple abstract types, such as point, vector3D, etc.
 *
 * And also used to implement function objects. Function objects are used as callbacks in standard template library.
 *
 */
class LearningStructures {
public:
    static void DrawLine(Point start, Point end) {
        std::cout << start.x << std::endl;
    }
};
