#include "rational.h"
#include <algorithm>
#include <numeric>


Rational::Rational(int numerator, int denominator) {
  if (denominator == 0) {
    throw RationalDivisionByZero();
  }
  int divider = std::gcd(std::abs(numerator), std::abs(denominator));
  numerator_ = numerator / divider;
  denominator_ = denominator / divider;
  if (denominator_ < 0) {
    numerator_ *= (-1);
    denominator_ *= (-1);
  }
}

Rational::Rational(int number) : Rational(number, 1) {}

Rational::Rational() : Rational(0) {}

int Rational::GetNumerator() const {
  return this->numerator_;
}

int Rational::GetDenominator() const {
  return this->denominator_;
}

void Rational::SetNumerator(int numerator) {
  int divider = std::gcd(std::abs(numerator), denominator_);
  numerator_ = numerator / divider;
  denominator_ /= divider;
  if (denominator_ < 0) {
    numerator_ *= (-1);
    denominator_ *= (-1);
  }
}

void Rational::SetDenominator(int denominator) {
  if (denominator == 0) {
    throw RationalDivisionByZero();
  }
  int divider = std::gcd(std::abs(denominator), numerator_);
  denominator_ = denominator / divider;
  numerator_ /= divider;
  if (denominator_ < 0) {
    numerator_ *= (-1);
    denominator_ *= (-1);
  }
}

Rational operator+(const Rational &x, const Rational &y) {
  int new_num = x.numerator_ * y.denominator_ + y.numerator_ * x.denominator_;
  int new_den = x.denominator_ * y.denominator_;
  int divider = std::gcd(new_den, new_num);
  Rational new_r(new_num / divider, new_den / divider);
  return new_r;
}

Rational operator-(const Rational &x, const Rational &y) {
  int new_num = x.numerator_ * y.denominator_ - y.numerator_ * x.denominator_;
  int new_den = x.denominator_ * y.denominator_;
  int divider = std::gcd(new_den, new_num);
  Rational new_r(new_num / divider, new_den / divider);
  return new_r;
}

Rational operator*(const Rational &x, const Rational &y) {
  int new_num = x.numerator_ * y.numerator_;
  int new_den = x.denominator_ * y.denominator_;
  int divider = std::gcd(new_den, new_num);
  Rational new_r(new_num / divider, new_den / divider);
  return new_r;
}

Rational operator/(const Rational &x, const Rational &y) {
  int new_num = x.numerator_ * y.denominator_;
  int new_den = x.denominator_ * y.numerator_;
  int divider = std::gcd(new_den, new_num);
  Rational new_r(new_num / divider, new_den / divider);
  return new_r;
}

Rational &operator+=(Rational &x, const Rational &y) {
  x = x + y;
  return x;
}

Rational &operator-=(Rational &x, const Rational &y) {
  x = x - y;
  return x;
}

Rational &operator/=(Rational &x, const Rational &y) {
  x = x / y;
  return x;
}

Rational &operator*=(Rational &x, const Rational &y) {
  x = x * y;
  return x;
}

Rational Rational::operator-() const {
  Rational new_r(-(this->GetNumerator()), this->GetDenominator());
  return new_r;
}

Rational Rational::operator+() const {
  Rational new_r(this->GetNumerator(), this->GetDenominator());
  return new_r;
}

Rational &Rational::operator--() {
  return *this -= Rational(1);
}

Rational Rational::operator--(int) {
  Rational old = *this;
  *this -= Rational(1);
  return old;
}

Rational &Rational::operator++() {
  return *this += Rational(1);
}

Rational Rational::operator++(int) {
  Rational old = *this;
  *this += Rational(1);
  return old;
}

bool operator==(const Rational &x, const Rational &y) {
  return x.GetNumerator() == y.GetNumerator() && x.GetDenominator() == y.GetDenominator();
}

bool operator!=(const Rational &x, const Rational &y) {
  return !(x == y);
}

bool operator>(const Rational &x, const Rational &y) {
  return (x - y).GetNumerator() > 0;
}

bool operator<(const Rational &x, const Rational &y) {
  return y > x;
}

bool operator>=(const Rational &x, const Rational &y) {
  return x == y || x > y;
}

bool operator<=(const Rational &x, const Rational &y) {
  return x == y || x < y;
}

std::istream &operator>>(std::istream &is, Rational &number) {
  char delimiter = ' ';
  int numerator = 0;
  is >> numerator;
  number.SetNumerator(numerator);
  if (is.peek() == '/') {
    int denominator = 0;
    is >> delimiter >> denominator;
    number.SetDenominator(denominator);
  } else {
    number.SetDenominator(1);
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, Rational number) {
  if (number.GetDenominator() == 1) {
    os << number.GetNumerator();
  } else {
    os << number.GetNumerator() << '/' << number.GetDenominator();
  }
  return os;
}