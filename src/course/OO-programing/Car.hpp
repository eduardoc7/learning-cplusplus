#pragma once
#include <iostream>

class Car {
    double fuel{0};
    double speed{0};
    int passengers{0};

public:
    void FillFuel(const double &value) {
        fuel = value;
    }

    void Accellerate() {
        speed++;
        fuel -= 0.5;
    }

    void Brake() {
        speed = 0;
    }

    void AddPassengers(const int &num) {
        passengers = num;
    }

    void Info() {
        std::cout << "Fuel: " << fuel << std::endl;
        std::cout << "Speed: " << speed << std::endl;
        std::cout << "Passengers: " << passengers << std::endl;
    }


    explicit Car(const double &amount_input); // parameterized constructor
    Car() = default; // default constructor
    ~Car(); // destructor
};

