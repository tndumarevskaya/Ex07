// Copyright 2020 Dumarevskaya
#ifndef INCLUDE_FRACTION_H_
#define INCKUDE_FRACTION_H_

#include <iostream>
#include <cstring>

class Fraction
{
 private:
  int numerator;
  int denominator;
 public:
  explicit Fraction(int num = 0, int den = 1):numerator{num}, denominator{den}{}; //конструктор с двумя параметрами, со значениями по - умолчанию(0, 1).
  Fraction(const Fraction& new_f) :numerator{ new_f.numerator }, denominator{ new_f.denominator }{};//конструктор копирования.
  std::string getValue(); //метод, возвращающий строку типа std::string, содержащую изображение дроби, например "1/2" или "-5/6".Дробь с единичным знаменателем выводится как целое число.
  int getNumerator(); //вернуть числитель.
  int getDenominator(); //вернуть знаменатель.
  Fraction operator+(const Fraction& frac); //сложение
  Fraction operator-(const Fraction& frac); //вычитание
  Fraction operator*(const Fraction& frac); //умножение
  Fraction operator/(const Fraction& frac); //деление
  Fraction& operator=(const Fraction& frac); //присваивание
 protected:
  Fraction normalize(); //закрытый метод нормировки(сокращения дроби 2 / 4 -> 1 / 2).
};

#endif // INCLUDE_FRACTION_H_
