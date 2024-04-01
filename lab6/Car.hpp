#pragma once

class Car {
public: 
    virtual ~Car(){};
    virtual const char* GetName() = 0;
    virtual float GetFuelCapacity() = 0;
    virtual float GetFuelConsumption() = 0;
    virtual float GetAverageSpeedRainy() = 0;
    virtual float GetAverageSpeedSunny() = 0;
    virtual float GetAverageSpeedSnowy() = 0;
};
