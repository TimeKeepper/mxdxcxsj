#include <spell.hpp>
#include <utils.h>

namespace spell {

Spell::Spell(std::string name, uint64_t mana_cost)
    : Name(RED + name + RESET), ManaCost(mana_cost) {
  std::cout << "Spell created. Name:" << this->Name << "\tmana_cost:" << BLUE
            << this->ManaCost << RESET << std::endl;
}

Spell::~Spell() {
  std::cout << "Spell " << this->Name << " destroyed." << std::endl;
}

SpellBook::SpellBook(std::vector<Spell *> spell_list) : SpellList(spell_list) {}
SpellBook::~SpellBook() {}

void SpellBook::displaySpell() {
  for (auto spell : this->SpellList) {
    std::cout << spell->Name << "\t" << "mana_cost: " << BLUE << spell->ManaCost
              << RESET << std::endl;
  }
}

SpellBook::SpellBook(const SpellBook &other, const Spell &new_spell)
    : SpellList(other.SpellList) {
  this->SpellList[1] = new Spell(new_spell.Name, new_spell.ManaCost);
}

} // namespace spell
