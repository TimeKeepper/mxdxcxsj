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

void fun_test(void) {
  funa(a);
  funb(b);
  funa(b);
  func();
  std::cout << a << ' ' << b << ' ' << c << '\n';
}

void FunCal_test(void) {
  int64_t a = 10, b = 20, c = 30;
  double ad = 10.0, bd = 20.0;
  std::cout << "Cal(a) = " << FunCal::Cal(a) << "\n";
  std::cout << "Cal(a, b) = " << FunCal::Cal(a, b) << "\n";
  std::cout << "Cal(ad, bd) = " << FunCal::Cal(ad, bd) << "\n";
  std::cout << "Cal(a, b, c) = " << FunCal::Cal(a, b, c) << "\n";
}

void arr_test(void) {
  my_Array::Array arr1(5);
  my_Array::Array arr2(5);

  for (int i = 0; i < 5; i++) {
    arr1[i] = i;
    arr2[i] = i * 2;
  }

  std::cout << "arr1 = " << arr1 << "\n";
  std::cout << "arr2 = " << arr2 << "\n";
  std::cout << "arr1 + arr2 = " << arr1 + arr2 << "\n";
}

int main(int argc, char **argv) {
  // FunCal_test();
  // fun_test();
  arr_test();
  return 0;
}
