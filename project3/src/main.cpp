#include <Array.hpp>
#include <FunCal.hpp>
#include <iostream>

int a = 300, b = 400, c = 500;

void funa(int c) {
  static int a = 5;
  a += c;
  std::cout << a << ' ' << c << ' ' << '\n';
}

void funb(int a) {
  a = b;
  std::cout << a << '\n';
}

void func() {
  int c = 0;
  std::cout << a << ' ' << b << ' ' << c << '\n';
  c -= 100;
}

int main(int argc, char **argv) {
  funa(a);
  funb(b);
  funa(b);
  func();
  std::cout << a << ' ' << b << ' ' << c << '\n';

  my_Array::Array arr1(5);
  my_Array::Array arr2(5);

  for (int i = 0; i < 5; i++) {
    arr1[i] = i;
    arr2[i] = i * 2;
  }

  std::cout << "arr1 = " << arr1 << "\n";
  std::cout << "arr2 = " << arr2 << "\n";
  std::cout << "arr1 + arr2 = " << arr1 + arr2 << "\n";

  return 0;
}
