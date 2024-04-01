#include "Ford.hpp"

const char* Ford::GetName() {
    return "Ford"; 
}

float Ford::GetFuelCapacity() {
    return 18.0f;
}

float Ford::GetFuelConsumption() {
    return 1.1f;
}

float Ford::GetAverageSpeedRainy() {
    return 140.0f;
}

float Ford::GetAverageSpeedSunny() {
    return 150.0f;
}

float Ford::GetAverageSpeedSnowy() {
    return 130.0f;
}
