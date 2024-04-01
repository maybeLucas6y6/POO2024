#include "Toyota.hpp"

const char* Toyota::GetName() {
    return "Toyota"; 
}

float Toyota::GetFuelCapacity() {
    return 15.0f;
}

float Toyota::GetFuelConsumption() {
    return 1.7f;
}

float Toyota::GetAverageSpeedRainy() {
    return 210.0f;
}

float Toyota::GetAverageSpeedSunny() {
    return 220.0f;
}

float Toyota::GetAverageSpeedSnowy() {
    return 230.0f;
}
