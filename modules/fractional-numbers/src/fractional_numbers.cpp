//
//  fractional_numbers.cpp
//  fractional_numbers
//
//  Created by Aleksei Khomenko.
//  Copyright © 2018 Aleksei Khomenko. All rights reserved.
//

#include "include/fractional_numbers.h"

#include <stdbool.h>
#include <string>
#include <iostream>

Rational::Rational(): a(0), b(1) {}
Rational::Rational(const int chislit, const int znamenat) {
    a = chislit;
    b = znamenat;
    if (b == 0) {
        throw std::string("Can't divide by zero");
    }
}
Rational::Rational(const Rational& r):
                   a(r.getChislitel()), b(r.getZnamenatel()) {}

    Rational& Rational::operator=(const Rational& s) {
    a = s.getChislitel();
    b = s.getZnamenatel();
    return *this;
}

Rational Rational::operator+(const Rational&s) const {
    int c;
    Rational Sum;
    Sum.a = a * s.b + b * s.a;
    Sum.b = b * s.b;
    c = Nod(Sum.b, Sum.a);
    Sum.a = (Sum.a)/c;
    Sum.b = (Sum.b)/c;
    return Sum;
}

Rational Rational::operator- (const Rational&s) const {
    int c;
    Rational Sum;
    Sum.a = a * s.b - b * s.a;
    Sum.b = b * s.b;
    c = Nod(Sum.b, Sum.a);
    Sum.a = (Sum.a)/c;
    Sum.b = (Sum.b)/c;
    return Sum;
}

Rational Rational::operator* (const Rational&s) const {
    int c;
    Rational Sum;
    Sum.a = a * s.a;
    Sum.b = b * s.b;
    c = Nod(Sum.b, Sum.a);
    Sum.a = (Sum.a)/c;
    Sum.b = (Sum.b)/c;
    return Sum;
}

Rational Rational::operator/ (const Rational&s) const {
    int c;
    Rational Sum;
    Sum.a = a * s.b;
    Sum.b = b * s.a;
    if  (s.a == 0) {
    throw std::string("Can't divide by zero");
    }
    c = Nod(Sum.b, Sum.a);
    Sum.a = (Sum.a)/c;
    Sum.b = (Sum.b)/c;
    return Sum;
}

int Rational::Nod(int c, int d) const {
    if (d == 0) {
    return c;
    } else {
    return Nod (d, c % d);
    }
}

int Rational::getChislitel() const {
    return a;
}

int Rational::getZnamenatel() const {
    return b;
}

void Rational::setChislitel(const int _a) {
    a = _a;
}

void Rational::setZnamenatel(const int _b) {
    b = _b;
}

bool Rational::operator == (const Rational& r) const {
    Rational tmp  = (*this - r);
    if ((tmp.a == 0) && (tmp.b == 1)) {
        return true;
    } else {
        return false;
    }
}

bool Rational::operator != (const Rational& r) const {
    return !(*this == r);
}
