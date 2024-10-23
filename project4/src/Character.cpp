#include <Character.hpp>
#include <Weapen.hpp>

#include <utils.h>

#include <cstdint>
#include <iostream>
#include <random>

namespace character {

Character::Character(std::string name, uint64_t health, uint64_t damege)
    : Health(health), MaxHealth(health), Damege(damege) {
  std::random_device rd;
  this->RandomGenerater = std::mt19937(rd());

  std::uniform_int_distribution<> colorDist(31, 37);
  int colorCode = colorDist(this->RandomGenerater);
  std::string ansiCode = "\033[1;" + std::to_string(colorCode) + "m";
  this->Name = ansiCode + name + "\033[0m";

  this->Skill_list = {
      std::bind(&Character::Skill_Attack, this, std::placeholders::_1),
      std::bind(&Character::Skill_Defense, this, std::placeholders::_1),
      std::bind(&Character::Skill_Heal, this, std::placeholders::_1),
  };

  std::cout << "Character " << this->Name << " created with " << this->Health
            << " health points." << this->Damege << " damage points."
            << std::endl;
} // namespace character

Character::~Character() {
  std::cout << "Character " << Name << " destroyed." << std::endl;
}

void Character::move(Character *target) {
  std::uniform_int_distribution<int> dist(0, this->Skill_num - 1);
  int ramdom_skill = dist(this->RandomGenerater);
  this->Skill_list[ramdom_skill](target);
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

void Character::add_Skill(std::function<void(Character *)> skill) {
  this->Skill_list.push_back(skill);
  this->Skill_num++;
}

void Character::change_Skill(std::function<void(Character *)> skill) {
  this->Skill_list[this->Skill_num - 1] = skill;
}

void Character::Attacked(uint64_t damege) {
  if (this->Health <= damege) {
    this->Health = 0;
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

void Character::add_Event_Handler(
    std::function<void(EventType, void *)> handler) {
  this->Event_Handler = handler;
}

void Character::notifyObervers(EventType type) {
  this->Event_Handler(type, this);
}

void Character::show_info() {
  std::cout << this->Name << " " << this->Health << "\u2764";
}

void observer::addObserverd(Character *character) {
  std::cout << "Observer add observerd " << character->Name << std::endl;
  this->Observerd.push_back(character);
  character->add_Event_Handler(std::bind(
      &observer::onEvent, this, std::placeholders::_1, std::placeholders::_2));
}

void observer::addWeapen(weapen::Weapen *weapen) {
  std::cout << "Observer add weapen " << weapen->Name << std::endl;
  this->Weapen_list.push_back(weapen);
}

void observer::onEvent(EventType type, void *sender) {
  switch (type) {
  case EventType::DEAD:
    this->loser = ((Character *)sender)->Name;
    this->is_end = true;
    break;
  default:
    std::cout << "Unknown event type." << std::endl;
    break;
  }
}

void observer::turn_one() {
  std::cout << "Turn " << this->turn_num << std::endl;

  if (this->is_end)
    return;
  this->Observerd[0]->move(this->Observerd[1]);
  if (this->is_end)
    return;
  this->Observerd[1]->move(this->Observerd[0]);

  for (auto weapen : this->Weapen_list) {
    weapen->turn();
  }

  this->Observerd[0]->show_info();
  std::cout << "\t";
  this->Observerd[1]->show_info();
  std::cout << std::endl;

  this->turn_num++;
}

void observer::fight() {
  this->is_end = false;
  this->turn_num = 0;

  while (!this->is_end) {
    this->turn_one();
  }

  std::cout << GREEN << "Game over." << this->loser << " Dead." << RESET
            << std::endl;
}

} // namespace character
