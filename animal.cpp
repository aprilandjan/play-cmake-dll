#include <iostream>
#include "animal.h"
#include "mylib_Export.h"

mylib_EXPORT Animal::Animal(std::string name) {}

mylib_EXPORT void Animal::printName() {
    std::cout << "Name is " << this->name << std::endl;
}