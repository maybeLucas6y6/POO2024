#include "Mazda.hpp"

const char* Mazda::GetName() {
    return "Mazda"; 
}

float Mazda::GetFuelCapacity() {
    return 20.0f;
}

float Mazda::GetFuelConsumption() {
    return 1.9f;
}

float Mazda::GetAverageSpeedRainy() {
    return 180.0f;
}

float Mazda::GetAverageSpeedSunny() {
    return 190.0f;
}

float Mazda::GetAverageSpeedSnowy() {
    return 170.0f;
}
