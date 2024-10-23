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

int main(int argc, char **argv) {
  fight_test();
  // weapen_test();
  return 0;
}
