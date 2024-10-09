#include <Array.hpp>

namespace my_Array {

Array::Array(int size) : size(size) {
  this->arr = new int[size];
  for (int i = 0; i < size; i++) {
    this->arr[i] = 0;
  }
}

Array::~Array() { delete[] this->arr; }

int &Array::operator[](int index) { return this->arr[index]; }

Array Array::operator+(const Array &other) {
  Array result(this->size);
  for (int i = 0; i < this->size; i++) {
    result[i] = this->arr[i] + other.arr[i];
  }
  return result;
}

std::ostream &operator<<(std::ostream &os, const Array &arr) {
  os << "[";
  for (int i = 0; i < arr.size; i++) {
    os << arr.arr[i];
    if (i < arr.size - 1) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

} // namespace my_Array
