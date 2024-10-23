#include <Weapen.hpp>
#include <iostream>
#include <type_traits>

namespace weapen {

Weapen::Weapen(std::string name, uint64_t duration) {
  this->Duration = duration;
  this->IsActive = false;

  std::random_device rd;
  this->RandomGenerater = std::mt19937(rd());

  std::uniform_int_distribution<int> colorDist(30, 37);
  int colorCode = colorDist(this->RandomGenerater);
  std::string ansiCode = "\033[1;" + std::to_string(colorCode) + "m";
  this->Name = ansiCode + name + "\033[0m";

  std::cout << "Weapen " << this->Name << " created." << std::endl;
}

Weapen::~Weapen() {
  std::cout << "Weapen " << this->Name << " destroyed." << std::endl;
}

void Weapen::turn() {
  if (!this->IsActive)
    return;
  if (--this->active_time == 0) {
    this->Deactivate();
  }
}

void Weapen::Activate() {
  std::cout << "Weapen " << this->Name << " activated." << std::endl;
  this->active_time = this->Duration;
  this->IsActive = true;
  this->sf_on();
}

void Weapen::Deactivate() {
  std::cout << "Weapen " << this->Name << " deactivated." << std::endl;
  this->active_time = 0;
  this->IsActive = false;
  this->sf_off();
}

void Weapen::sf_on() {
  std::cout << "Weapen " << this->Name << " have not special function."
            << std::endl;
}

void Weapen::sf_off() {}

void Weapen::CheckStatus() {
  std::cout << "Name: " << this->Name << ", Duration: " << this->Duration
            << ", IsActive " << this->IsActive << std::endl;
}

Shiled::Shiled(std::string name, uint64_t duration, uint64_t strength)
    : Weapen(name, duration), strength(strength) {}

Shiled::~Shiled() {}

void Shiled::sf_on() { this->IncreaseStrength(10); }

void Shiled::sf_off() { this->DecreaseStrength(10); }

void Shiled::CheckStatus() {
  std::cout << "Name: " << this->Name << ", Duration: " << this->Duration
            << ", IsActive " << this->IsActive
            << ", Strength: " << this->strength << std::endl;
}

void Shiled::IncreaseStrength(uint64_t amount) { this->strength += amount; }
void Shiled::DecreaseStrength(uint64_t amount) { this->strength -= amount; }

} // namespace weapen