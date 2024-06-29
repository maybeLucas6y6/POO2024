#include <iostream>

#include "Apple.hpp"

Apple::Apple(int price, int quantity, std::string origin)
    : price(price)
    , quantity(quantity)
    , origin(origin)
{

}

std::string Apple::GetType() {
    return "Apple";
}

int Apple::GetQuantity() {
    return quantity;
}

int Apple::GetPrice() {
    return price;
}

void Apple::Print() {
    std::cout << GetType()
        << " (from="
        << origin
        << ") "
        << "Price="
        << GetPrice()
        << " Quantity="
        << GetQuantity();
}
