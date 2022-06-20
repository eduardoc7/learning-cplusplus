#pragma once

/**
* @brief Circular reference occurs when we have two smart pointer point to each other and the
 * destructor is not called.
 * We basically can handle with this issue using a weak pointer, that not increment the reference count
*/

