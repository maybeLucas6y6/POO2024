#pragma once

class Car;

enum class Weather {
    Rainy,
    Sunny,
    Snowy
};

class Circuit {
    float length;
    Weather weather;
    Car* cars[32];
    unsigned int size, capacity;
    struct RaceResults {
        bool finished = false;
        float time = 0;
        Car* car = nullptr;
    } results[32];
public:
    Circuit();
    ~Circuit();
    void SetLength(unsigned int length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish() const;
};
