#ifndef RATIONAL_H
#define RATIONAL_H
#include <cstdint>
#include <iostream>

class Rational {
  int numerator_;
  int denominator_;

  public:
  Rational(int numerator, int denominator);
  Rational(int number); // NOLINT
  Rational();
  int GetNumerator() const;
  int GetDenominator() const;
  void SetNumerator(int);
  void SetDenominator(int);
  friend Rational operator+(const Rational &x, const Rational &y);
  friend Rational operator-(const Rational &x, const Rational &y);
  friend Rational operator/(const Rational &x, const Rational &y);
  friend Rational operator*(const Rational &x, const Rational &y);
  friend Rational &operator+=(Rational &x, const Rational &y);
  friend Rational &operator-=(Rational &x, const Rational &y);
  friend Rational &operator/=(Rational &x, const Rational &y);
  friend Rational &operator*=(Rational &x, const Rational &y);
  Rational operator-() const;
  Rational operator+() const;
  Rational &operator--();
  Rational &operator++();
  Rational operator--(int);
  Rational operator++(int);
  friend bool operator==(const Rational &x, const Rational &y);
  friend bool operator!=(const Rational &x, const Rational &y);
  friend bool operator>(const Rational &x, const Rational &y);
  friend bool operator<(const Rational &x, const Rational &y);
  friend bool operator<=(const Rational &x, const Rational &y);
  friend bool operator>=(const Rational &x, const Rational &y);
  friend std::istream &operator>>(std::istream &is, Rational &number);
  friend std::ostream &operator<<(std::ostream &os, Rational number);
};

class RationalDivisionByZero {};

#endif