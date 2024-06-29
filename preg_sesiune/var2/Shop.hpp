#pragma once

#include <vector>

#include "Article.hpp"

class Shop {
    std::vector<Article*> items;
public:
    ~Shop();
    Shop& Add(Article* article);
    int GetTotalPrice();
    int GetQuantity(std::string type);
    void List();
};
