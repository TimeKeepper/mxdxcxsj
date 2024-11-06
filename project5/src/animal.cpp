#include <animal.hpp>
#include <iostream>
#include <utils.h>

namespace animal {

Animal::Animal(std::string name) : Name(RED + name + RESET) {}

Animal::~Animal() {}

void Animal::show(void) { std::cout << this->Name << std::endl; }

} // namespace animal
