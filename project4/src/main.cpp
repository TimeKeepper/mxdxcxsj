#include "Weapen.hpp"
#include <Character.hpp>
#include <iostream>

void fight(character::Character *A, character::Character *B,
           character::observer *ob) {
  static bool turn = true;
  while (!ob->is_end) {
    if (turn) {
      A->move(B);
      turn = false;
    } else {
      B->move(A);
      turn = true;
    }
  }
  std::cout << "Game Over!" << std::endl;
}

void fight_test() {
  character::observer *ob = new character::observer();
  character::Character *Warrior = new character::Character("Warrior", 30, 6);
  character::Character *Monster = new character::Character("Monster", 30, 6);

  Warrior->addObserver(ob);
  Monster->addObserver(ob);

  fight(Warrior, Monster, ob);

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
  // fight_test();
  weapen_test();
  return 0;
}
