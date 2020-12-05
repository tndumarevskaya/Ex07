// Copyright 2020 Dumarevskaya
#include "Fraction.h"
#include <string>

std::string Fraction::getValue() {
  std::string str;
  if (denominator == 0)
    str = "Error: impossible operation";
  else {
    *this = this->normalize();
    if (denominator == 1 || numerator == 0) {
      str = std::to_string(numerator);
    }
    else {
      str = std::to_string(numerator) + "/" + std::to_string(denominator);
    }
  }
  return str;
};

int Fraction::getNumerator() {
  return numerator;
};
int Fraction::getDenominator() {
  return denominator;
};

Fraction Fraction::operator+(const Fraction& frac) {
  if (denominator == frac.denominator) {
    Fraction new_f(numerator + frac.numerator, denominator);
    return new_f;
  }
  else {
    Fraction new_f;
    new_f.numerator = numerator * frac.denominator + denominator * frac.numerator;
    new_f.denominator = denominator * frac.denominator;
    return new_f;
  }
};

Fraction Fraction::operator-(const Fraction& frac) {
  if (denominator == frac.denominator) {
    Fraction new_f(numerator - frac.numerator, denominator);
    return new_f;
  }
  else {
    Fraction new_f;
    new_f.numerator = numerator * frac.denominator - denominator * frac.numerator;
    new_f.denominator = denominator * frac.denominator;
    return new_f;
  }
};

Fraction Fraction::operator*(const Fraction& frac) {
  return Fraction(numerator * frac.numerator, denominator * frac.denominator);
};

Fraction Fraction::operator/(const Fraction& frac) {
  try { //ищем исключени€, которые выбрасываютс€ в блоке try, и отправл€ем их дл€ обработки в блок(и) catch
    if (frac.numerator == 0)
      throw 0;
      return Fraction(numerator * frac.denominator, denominator * frac.numerator);
  }
  catch (int) { // обработка исключений типа int
    denominator = 0;
  }
  return *this;
};

Fraction& Fraction::operator=(const Fraction& frac) {
  //проверка на самоприсваивание
  if (this == &frac) {
    return *this;
  }
  numerator = frac.numerator;
  denominator = frac.denominator;
  return *this;
};

Fraction Fraction::normalize() {
  int min = numerator, max = denominator;
  if (min == 0)
    return *this;
  while (max % min != 0) {
    int temp = min;
    min = max % min;
    max = temp;
  }
  numerator = numerator / min;
  denominator = denominator / min;
  return *this;
};