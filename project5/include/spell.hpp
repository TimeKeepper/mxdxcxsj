#ifndef __SPELL_HPP__
#define __SPELL_HPP__

#include <iostream>
#include <vector>

namespace spell {

class Spell {
public:
  uint64_t ManaCost;
  std::string Name;
  Spell(std::string name, uint64_t mana_cost);
  ~Spell();
};

class SpellBook {
private:
  std::vector<Spell *> SpellList;

public:
  SpellBook(std::vector<Spell *> spell_list);
  ~SpellBook();

  SpellBook(const SpellBook &other, const Spell &new_spell);
  SpellBook(const SpellBook &other, const std::string &spell_name);

  void displaySpell();
};

} // namespace spell

#endif // __SPELL_HPP__
