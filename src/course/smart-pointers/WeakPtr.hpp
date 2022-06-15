#pragma once

#include <iostream>
#include <memory>

/**
 * @brief How shared_ptr work internally:
 * When we create a object with shared_ptr, we'll create a control block.
 * A control block will contain information about the memory that you had allocate to this object.
 * One thing is the reference count.
 *
 * If after that, we create a weak_pointer. We can note that, weak pointer is always
 * initialized with the shared pointer.
 * The weak pointer internally will point to the control block.
 */
class Printer {
    std::weak_ptr<int> m_pValue{};
public:
    void setValue(std::weak_ptr<int> p) {
        m_pValue = p;
    }

    void print() {
        if(m_pValue.expired()) {
            std::cout << "Resource in no longer available" << std::endl;

            return;
        }

        auto shared_pointer_by_lock = m_pValue.lock();
        std::cout << "Value is: " << *shared_pointer_by_lock << std::endl;
        std::cout << "Ref Count: " << shared_pointer_by_lock.use_count() << std::endl;
    }
};

static void testWeakPtr() {
    Printer printer;

    int num{};
    std::cin >> num;
    std::shared_ptr<int> p{new int{num}};

    printer.setValue(p);

    if(*p > 10) {
        p = nullptr;
    }

    printer.print();
}

