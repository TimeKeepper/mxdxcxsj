#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <cstdint>
#include <functional>
#include <random>
#include <string>
#include <vector>

namespace weapen {
class Weapen;
} // namespace weapen

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
  void Skill_Attack(Character *);
  void Skill_Defense(Character *);
  void Skill_Heal(Character *);

public:
  std::string Name;
  Character(std::string name, uint64_t health, uint64_t damege);
  ~Character();

  void move(Character *);

  uint64_t Skill_num = 3;
  std::vector<std::function<void(Character *)>> Skill_list;
  void add_Skill(std::function<void(Character *)> skill);
  void change_Skill(std::function<void(Character *)> skill);

  void Attacked(uint64_t damage);
  void Healed(uint64_t heal);
  void add_Event_Handler(std::function<void(EventType, void *sender)> handler);
  void notifyObervers(EventType);

  void show_info();
};

class observer {
private:
  uint64_t turn_num = 0;
  std::vector<Character *> Observerd;
  std::vector<weapen::Weapen *> Weapen_list;
  std::string loser;

public:
  bool is_end = false;
  void addObserverd(Character *);
  void addWeapen(weapen::Weapen *);
  void onEvent(EventType, void *sender);
  void turn_one();
  void fight();
};

} // namespace character

#endif
