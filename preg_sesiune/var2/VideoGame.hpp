#pragma once

#include "Article.hpp"

class VideoGame : public Article {
    int price, quantity;
    std::string platform, name;
public:
    VideoGame(int price, int quantity, std::string platform, std::string name);
    std::string GetType() override;
    int GetQuantity() override;
    int GetPrice() override;
    void Print() override;
};
