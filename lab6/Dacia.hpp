#pragma once

#include "Car.hpp"

class Dacia : public Car {
public:
    Dacia(){}
    virtual const char* GetName() override final;
    virtual float GetFuelCapacity() override final;
    virtual float GetFuelConsumption() override final;
    virtual float GetAverageSpeedRainy() override final;
    virtual float GetAverageSpeedSunny() override final;
    virtual float GetAverageSpeedSnowy() override final;
};
