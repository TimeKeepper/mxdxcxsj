#include <algorithm>
#include <animal.hpp>
#include <book.hpp>
#include <iostream>
#include <spell.hpp>
#include <utils.h>

void mention_1(void) {
  std::vector<spell::Spell *> spells = {
      new spell::Spell("Fireball", 4),
      new spell::Spell("Frostbolt", 2),
  };

  spell::SpellBook book1(spells);
  book1.displaySpell();

  spell::Spell new_spell("Arcane Missiles", 1);
  spell::SpellBook book2(book1, new_spell);
  book2.displaySpell();
}

animal::Animal &transferm(const std::string &str) {
  std::vector<std::string> animals = {"cat", "dog", "bird"};

  auto it = find(animals.begin(), animals.end(), str);

  animal::Animal *animal;

  if (it == animals.end()) {
    animal = new animal::Animal("mysteryCreature");
  } else {
    animal = new animal::Animal(*it);
  }

  return *animal;
}

void mention_2(void) {
  std::string str;
  std::cout << "Enter an animal: ";
  std::cin >> str;
  transferm(str).show();
}

void mention_3(void) {
  book::Book book1("Abook", 1);
  book::Book book2("Bbook", 2);

  book::BorrowList list;

  book::BorrowRecord record1("Xiaoming", "2021-01-01", book1, list);
  book::BorrowRecord record2("Xiaohong", "2021-01-02", book2, list);

  book::BorrowRecord record3(record1, "2021-01-10");
}

int main(int argc, char **argv) {
  mention_3();

  std::cout << GREEN << "Program End" << RESET << std::endl;
  return 0;
}
