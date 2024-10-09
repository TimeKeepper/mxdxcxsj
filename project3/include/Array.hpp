#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>

namespace my_Array {

class Array {
private:
  int *arr;
  int size;

public:
  Array(int size);

  ~Array();

  int &operator[](int index);

  Array operator+(const Array &other);

  friend std::ostream &operator<<(std::ostream &os, const Array &arr);
};

} // namespace my_Array

#endif
