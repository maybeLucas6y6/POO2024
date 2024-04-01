#include "Dacia.hpp"

const char* Dacia::GetName() {
    return "Dacia"; 
}

float Dacia::GetFuelCapacity() {
    return 10.0f;
}

float Dacia::GetFuelConsumption() {
    return 1.0f;
}

float Dacia::GetAverageSpeedRainy() {
    return 110.0f;
}

float Dacia::GetAverageSpeedSunny() {
    return 120.0f;
}

float Dacia::GetAverageSpeedSnowy() {
    return 100.0f;
}
