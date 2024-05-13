#pragma once

#include <exception>

class ExceptionInvalidIndex : public std::exception {
    virtual const char* what() const throw() {
        return "Index out of bounds!";
    }
};
