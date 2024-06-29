#include <iostream>

#include "Shop.hpp"

Shop::~Shop() {
    for (Article* article : items) {
        delete article;
    }
}

Shop& Shop::Add(Article* article) {
    items.push_back(article);
    return *this;
}

int Shop::GetTotalPrice() {
    int total = 0;
    for (Article* article : items) {
        total += article->GetPrice() * article->GetQuantity(); 
    }
    return total;
}

int Shop::GetQuantity(std::string type) {
    int total = 0;
    for (Article* article : items) {
        if (article->GetType() == type) {
            total += article->GetQuantity(); 
        }
    }
    return total;
}

void Shop::List() {
    for (Article* article : items) {
        article->Print();
        std::cout << "\n";
    }
}
