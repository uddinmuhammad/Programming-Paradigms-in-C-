//
//  Rational.cpp
//  Lab4
//
//  Created by Moeen Khan on 11/6/20.
//
//
//#include "Rational.hpp"
//#ifndef RATIONAL_H
//#define RATIONAL_H


#include "Rational.hpp"
#include<iostream>
#include<cstdlib>
#include<string>
#include "RationalException.h"
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include "gcd.h"
using namespace std;

Rational::Rational(int num, int denom)
{
    if(denom == 0) throw RationalException("Denominator cannot be 0");

    normalize(num, denom);

    Rational::num = num;
    Rational::denom = denom;
}


int Rational::getNumerator() const { return num; }
int Rational::getDenominator() const { return denom; }


Rational &Rational::addInPlace(const Rational &r)
{
    int commonD = denom * r.getDenominator();
    int numerator1 = num * r.getDenominator();
    int numerator2 = r.getNumerator() * denom;

    num = numerator1 + numerator2;
    denom = commonD;
    normalize(num, denom);
    
    return *this;
}

//Rational &Rational::subInPlace(const Rational &r) { return addInPlace(r.neg()); }

Rational &Rational::subInPlace(const Rational &r){
    addInPlace(r.neg());
    return *this;
}

Rational &Rational::mulInPlace(const Rational &r)
{
    num *= r.num;
    denom *= r.getDenominator();
    normalize(num, denom);

    return *this;
}

//Rational &Rational::divInPlace(const Rational &r) { return mulInPlace(r.inv()); }

Rational &Rational::divInPlace(const Rational &r){
    mulInPlace(r.inv());

    return *this;
}

//Rational Rational::add(const Rational &r) const
//{
//    Rational newR(num, denom);
//    return newR.addInPlace(r);
//}

Rational Rational::add(const Rational &r) const{
    Rational rational(num, denom);
    rational.addInPlace(r);
    return rational;
}

//Rational Rational::sub(const Rational &r) const
//{
//    Rational newR(num, denom);
//    return newR.subInPlace(r);
//}

Rational Rational::sub(const Rational &r) const{
    Rational rational(num, denom);
    rational.subInPlace(r);
    return rational;
}

//Rational Rational::mul(const Rational &r) const
//{
//    Rational newR(num, denom);
//    return newR.mulInPlace(r);
//}

Rational Rational::mul(const Rational &r) const{
    Rational rational(num, denom);
    rational.mulInPlace(r);

    return rational;
}

//Rational Rational::div(const Rational &r) const
//{
//    Rational newR(num, denom);
//    return newR.divInPlace(r);
//}

Rational Rational::div(const Rational &r) const{
    Rational rational(num, denom);
    rational.divInPlace(r);
    return rational;
}

 

void normalize(int &num, int &denom){
    int g = gcd(num, denom);
    
    num /= g;
    denom /= g;
}



Rational Rational::neg() const {
    return Rational(num * -1, denom);
}
Rational Rational::inv() const {
    return Rational(denom, num);
}

bool Rational::equals(const Rational &r) const {
    return this->compareTo(r) == 0;
}

int Rational::compareTo(const Rational &r) const
{
    int lhs = num * r.getDenominator();
    int rhs = denom * r.getNumerator();
    return lhs < rhs ? -1 : (lhs > rhs ? 1 : 0);
}
