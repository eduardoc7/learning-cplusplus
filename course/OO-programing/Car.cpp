#include "Car.hpp"

Car::Car(const double &amount_input) : fuel(amount_input) {}

Car::~Car() {
    std::cout << "My destructor here!" << std::endl;
}
