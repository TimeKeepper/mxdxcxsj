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

int main(int argc, char **argv) {
  character::observer *ob = new character::observer();
  character::Character *Warrior = new character::Character("Warrior", 30, 6);
  character::Character *Monster = new character::Character("Monster", 30, 6);

  Warrior->addObserver(ob);
  Monster->addObserver(ob);

  fight(Warrior, Monster, ob);

  delete Warrior, Monster, ob;
  return 0;
}
