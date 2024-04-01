#include "Mercedes.hpp"

const char* Mercedes::GetName() {
    return "Mercedes"; 
}

float Mercedes::GetFuelCapacity() {
    return 12.0f;
}

float Mercedes::GetFuelConsumption() {
    return 1.5f;
}

float Mercedes::GetAverageSpeedRainy() {
    return 170.0f;
}

float Mercedes::GetAverageSpeedSunny() {
    return 180.0f;
}

float Mercedes::GetAverageSpeedSnowy() {
    return 160.0f;
}
