//
//  Rational.hpp
//  Lab4
//
//  Created by Moeen Khan on 11/6/20.
//

#ifndef RATIONAL_H
#define RATIONAL_H
#include <stdio.h>
#include <iostream>

class Rational {
public:
    
    Rational(int num = 0, int denom =1);
    
    
    int getNumerator() const;
    int getDenominator() const;
    
    Rational add(const Rational &r) const;
    Rational sub(const Rational &r) const;
    Rational mul(const Rational &r) const;
    Rational div(const Rational &r) const;

    Rational &addInPlace(const Rational &r);
    Rational &subInPlace(const Rational &r);
    Rational &mulInPlace(const Rational &r);
    Rational &divInPlace(const Rational &r);
    
    bool equals(const Rational &r) const;
    int compareTo(const Rational &r) const;
    void normalize(int &num, int &denom);
    
    Rational neg() const;
    Rational inv() const;

    void print(std::ostream &os) const;
private:
    int num;
    int denom;

};

inline std::ostream &operator <<(std::ostream &os, const Rational &r) {r.print(os); return os;}

#endif  /* Rational_hpp */
