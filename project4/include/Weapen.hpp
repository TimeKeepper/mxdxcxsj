#ifndef __WEAPEN_HPP__
#define __WEAPEN_HPP__

#include <cstdint>
#include <random>
#include <string>

namespace character {
class Character;
}

namespace weapen {

class Weapen {
private:
  uint64_t active_time;

protected:
  character::Character *Owner;
  std::mt19937 RandomGenerater;
  uint64_t Duration;
  bool IsActive;

public:
  std::string Name;
  Weapen(std::string name, uint64_t duration);
  ~Weapen();

  void turn();
  void Activate();
  void Deactivate();
  void bind_owner(character::Character *owner);
  virtual void Skill(character::Character *target);
  virtual void sf_on();
  virtual void sf_off();
  virtual void CheckStatus();
};

class Shiled : public Weapen {
private:
  uint64_t strength;

public:
  Shiled(std::string name, uint64_t duration, uint64_t strength);
  ~Shiled();
  void Skill(character::Character *target) override;
  void sf_on() override;
  void sf_off() override;
  void CheckStatus() override;
  void IncreaseStrength(uint64_t amount);
  void DecreaseStrength(uint64_t amount);
};

} // namespace weapen

#endif
