#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>

namespace animal {

class Animal {

public:
  std::string Name;

  Animal(std::string name);
  ~Animal();

  void show(void);
};

} // namespace animal

#endif // __ANIMAL_HPP__
