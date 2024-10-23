#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <cstdint>
#include <functional>
#include <random>
#include <string>
#include <vector>

namespace character {

enum class EventType { DEAD };

class Character {
private:
  std::mt19937 RandomGenerater;
  std::function<void(Character *)> Skill;
  std::function<void(EventType, void *sender)> Event_Handler;
  uint64_t Health;
  uint64_t MaxHealth;
  uint64_t Damege;

public:
  std::string Name;
  Character(std::string name, uint64_t health, uint64_t damege);
  ~Character();

  void move(Character *);

  void Skill_change();
  void Skill_Attack(Character *);
  void Skill_Defense(Character *);
  void Skill_Heal(Character *);

  void Attacked(uint64_t damage);
  void Healed(uint64_t heal);
  void add_Event_Handler(std::function<void(EventType, void *sender)> handler);
  void notifyObervers(EventType);
};

class observer {
private:
  std::vector<Character *> Observerd;
  std::string loser;

public:
  bool is_end = false;
  void addObserverd(Character *);
  void onEvent(EventType, void *sender);
  void turn_one();
  void fight();
};

} // namespace character

#endif
