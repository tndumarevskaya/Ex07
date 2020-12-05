// Copyright 2020 Dumarevskaya
#include "Fraction.h"

int main() {
  Fraction a(2, 4); // 1/2
  Fraction b(a);
  Fraction c, d;
  std::cout << c.getValue() << std::endl; // 0
  d = a / c;
  std::cout << d.getValue() << std::endl;
  a = b;
  c = a * b;
  std::cout << c.getValue(); // 1
  return 0;
}