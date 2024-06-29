#pragma once

#include "Article.hpp"

class Book : public Article {
    int price, quantity;
    std::string title, author;
public:
    Book(int price, int quantity, std::string title, std::string author);
    std::string GetType() override;
    int GetQuantity() override;
    int GetPrice() override;
    void Print() override;
};
