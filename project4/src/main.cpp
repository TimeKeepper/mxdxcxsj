#include "Weapen.hpp"
#include <Character.hpp>

void fight_test() {
  character::observer *ob = new character::observer();
  character::Character *Warrior = new character::Character("Warrior", 30, 6);
  character::Character *Monster = new character::Character("Monster", 30, 6);

  ob->addObserverd(Warrior);
  ob->addObserverd(Monster);

  ob->fight();

  delete Warrior;
  delete Monster;
  delete ob;
}

void weapen_test() {
  weapen::Shiled *test = new weapen::Shiled("Magic Shield", 5, 5);
  test->CheckStatus();
  test->Activate();
  test->CheckStatus();
  test->turn();
  test->turn();
  test->turn();
  test->turn();
  test->turn();
  test->CheckStatus();
  delete test;
}

void final_test() {
  character::observer *ob = new character::observer();
  character::Character *Warrior = new character::Character("Warrior", 30, 6);
  character::Character *Monster = new character::Character("Monster", 50, 6);

  weapen::Shiled *weapen1 = new weapen::Shiled("Magic Shield", 3, 3);
  weapen1->bind_owner(Warrior);

  ob->addObserverd(Warrior);
  ob->addObserverd(Monster);
  ob->addWeapen(weapen1);

  ob->fight();

  delete Warrior;
  delete Monster;
  delete ob;
  delete weapen1;
}

int main(int argc, char **argv) {
  // fight_test();
  // weapen_test();
  final_test();
  return 0;
}
