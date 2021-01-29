//
//  rational.cpp
//  Lab7
//
//  Created by Moeen Khan on 12/10/20.
//

#include "rational.h"
#include "Rational_Exception.h"
#include "gcd.h"


void normalize(int &num, int &denom){
    int g = gcd(num, denom);
    
    num /= g;
    denom /= g;
}

Rational::Rational(int num, int denom)
{
    if(denom == 0) throw RationalException("Denominator cannot be 0");

    normalize(num, denom);

    Rational::num = num;
    Rational::denom = denom;
}

Rational &Rational::operator +=(const Rational &r){
    int commonD = denom * r.getDenominator();
    int numerator1 = num * r.getDenominator();
    int numerator2 = r.getNumerator() * denom;

    num = numerator1 + numerator2;
    denom = commonD;
    normalize(num, denom);
    
    return *this;
}

Rational &Rational::operator -=(const Rational &r){
    return *this += -r;
}

Rational &Rational::operator *=(const Rational &r){
    num *= r.num;
    denom *= r.getDenominator();
    normalize(num, denom);

    return *this;
}

Rational &Rational::operator /=(const Rational &r){
    return *this *= r.inv();
}

Rational Rational::operator-() const {
    return Rational(num * -1, denom);
}

Rational Rational::inv() const {
    return Rational(denom, num);
}

int Rational::compareTo(const Rational &r) const
{
    int lhs = num * r.getDenominator();
    int rhs = denom * r.getNumerator();
    return lhs < rhs ? -1 : (lhs > rhs ? 1 : 0);
}

Rational operator +(const Rational &r1, const Rational &r2){
    Rational rational(r1.getNumerator(), r1.getDenominator());
    return rational += r2;
}

Rational operator -(const Rational &r1, const Rational &r2){
    Rational rational(r1.getNumerator(), r1.getDenominator());
    return rational -= r2;
}

Rational operator *(const Rational &r1, const Rational &r2){
    Rational rational(r1.getNumerator(), r1.getDenominator());
    return rational *= r2;
}

Rational operator /(const Rational &r1, const Rational &r2){
    Rational rational(r1.getNumerator(), r1.getDenominator());
    return rational /= r2;
}

bool operator ==(const Rational &r1, const Rational &r2){
    return r1.compareTo(r2) == 0;
}

int Rational::getNumerator() const { return num; }
int Rational::getDenominator() const { return denom; }

std::ostream &operator <<(std::ostream &os, const Rational &r)
{
    r.print(os);
    return os;
}

void Rational::print(std::ostream &os) const
{
    if(denom == 1) os << num;
    else os << num << "/" << denom;
}
