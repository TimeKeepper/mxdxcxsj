#include <Character.hpp>

#include <cstdint>
#include <iostream>
#include <random>

namespace character {

void observer::onEvent(EventType type, void *sender) {
  switch (type) {
  case EventType::DEAD:
    std::cout << ((Character *)sender)->Name << " is dead." << std::endl;
    this->is_end = true;
    break;
  default:
    std::cout << "Unknown event type." << std::endl;
    break;
  }
}

Character::Character(std::string name, uint64_t health, uint64_t damege)
    : Health(health), MaxHealth(health), Damege(damege) {
  std::random_device rd;
  this->RandomGenerater = std::mt19937(rd());

  std::uniform_int_distribution<> colorDist(30, 37);
  int colorCode = colorDist(this->RandomGenerater);
  std::string ansiCode = "\033[1;" + std::to_string(colorCode) + "m";
  this->Name = ansiCode + name + "\033[0m";

  std::cout << "Character " << this->Name << " created with " << this->Health
            << " health points." << this->Damege << " damage points."
            << std::endl;
}

Character::~Character() {
  std::cout << "Character " << Name << " destroyed." << std::endl;
}

void Character::move(Character *target) {
  this->Skill_change();
  this->Skill(target);
}

void Character::Skill_change() {
  std::uniform_int_distribution<int> dist(1, 3);
  int random_skill = dist(this->RandomGenerater);
  switch (random_skill) {
  case 1:
    this->Skill =
        std::bind(&Character::Skill_Attack, this, std::placeholders::_1);
    break;
  case 2:
    this->Skill =
        std::bind(&Character::Skill_Defense, this, std::placeholders::_1);
    break;
  case 3:
    this->Skill =
        std::bind(&Character::Skill_Heal, this, std::placeholders::_1);
    break;
  default:
    break;
  }
}

void Character::Skill_Attack(Character *target) {
  std::cout << this->Name << " attacks " << target->Name << std::endl;

  target->Attacked(this->Damege);
}

void Character::Skill_Defense(Character *target) {
  std::cout << this->Name << " defends against " << target->Name << std::endl;

  this->Healed(4);
  target->Attacked(2);
}

void Character::Skill_Heal(Character *target) {
  std::cout << this->Name << " heals itself" << std::endl;

  this->Healed(6);
}

void Character::Attacked(uint64_t damege) {
  if (this->Health < damege) {
    this->notifyObervers(EventType::DEAD);
    return;
  }

  this->Health -= damege;
}

void Character::Healed(uint64_t health) {
  if (this->Health + health > this->MaxHealth) {
    this->Health = this->MaxHealth;
    return;
  }
  this->Health += health;
}

void Character::addObserver(observer *observer) {
  std::cout << "Character " << this->Name << " add observer" << std::endl;
  this->Observers.push_back(observer);
}

void Character::notifyObervers(EventType type) {
  for (auto observer : this->Observers) {
    observer->onEvent(type, this);
  }
}

} // namespace character
