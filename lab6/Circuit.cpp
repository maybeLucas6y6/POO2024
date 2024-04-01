#include "Circuit.hpp"
#include "Car.hpp"
#include "Cars.hpp"

#include <iostream>

Circuit::Circuit()
    : cars{}
    , size(0)
    , capacity(32)
    , results{}
{

}

Circuit::~Circuit() {
    for (int i = 0; i < this->size; i++) {
        delete this->cars[i];
    }
}

void Circuit::SetLength(unsigned int length) {
    this->length = length;
}

void Circuit::SetWeather(Weather weather) {
    this->weather = weather;
}

void Circuit::AddCar(Car* car) {
    if (this->size < this->capacity) {
        this->cars[this->size] = car;
        this->size++;
    }
}

void Circuit::Race() {
    for (int i = 0; i < this->size; i++) {
        this->results[i].car = this->cars[i];
        // (L) / (L/km) = km
        float dist = this->cars[i]->GetFuelCapacity() / this->cars[i]->GetFuelConsumption();
        this->results[i].finished = (dist >= this->length);
        switch (this->weather) {
            case Weather::Rainy:
                // km / (km/h) = h
                dist /= this->cars[i]->GetAverageSpeedRainy();
                break;
            case Weather::Sunny:
                dist /= this->cars[i]->GetAverageSpeedSunny();
                break;
            case Weather::Snowy:
                dist /= this->cars[i]->GetAverageSpeedSnowy();
                break;
            default:
            break;
        }
        this->results[i].time = dist;
    }
}

void Circuit::ShowFinalRanks() {
    for (int i = 0; i < this->size - 1; i++) {
        for (int j = i; j < this->size; j++) {
            if (this->results[i].time < this->results[j].time) {
                auto temp = this->results[i];
                this->results[i] = this->results[j];
                this->results[j] = temp;
            }
        }
    }

    std::cout << "Finished: \n";
    for (int i = 0; i < this->size; i++) {
        if (this->results[i].finished == false) {
            break;
        }

        std::cout << this->results[i].car->GetName() << " " << this->results[i].time << "\n";
    }
}

void Circuit::ShowWhoDidNotFinish() const {
    std::cout << "Not Finished: \n";
    int i = 0;
    while (this->results[i].finished == true) {
        i++;
    }

    for (; i < this->size; i++) {
        std::cout << this->results[i].car->GetName() << " " << this->results[i].time << "\n";
    }
}
