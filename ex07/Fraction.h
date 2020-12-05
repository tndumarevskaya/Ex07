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
  explicit Fraction(int num = 0, int den = 1):numerator{num}, denominator{den}{}; //����������� � ����� �����������, �� ���������� �� - ���������(0, 1).
  Fraction(const Fraction& new_f) :numerator{ new_f.numerator }, denominator{ new_f.denominator }{};//����������� �����������.
  std::string getValue(); //�����, ������������ ������ ���� std::string, ���������� ����������� �����, �������� "1/2" ��� "-5/6".����� � ��������� ������������ ��������� ��� ����� �����.
  int getNumerator(); //������� ���������.
  int getDenominator(); //������� �����������.
  Fraction operator+(const Fraction& frac); //��������
  Fraction operator-(const Fraction& frac); //���������
  Fraction operator*(const Fraction& frac); //���������
  Fraction operator/(const Fraction& frac); //�������
  Fraction& operator=(const Fraction& frac); //������������
 protected:
  Fraction normalize(); //�������� ����� ����������(���������� ����� 2 / 4 -> 1 / 2).
};

#endif // INCLUDE_FRACTION_H_
