/*
TITLE: PROGRAMMING II LABS                   SUBTITLE: P0

AUTHOR 1: Alexandre Borrazás Mancebo LOGIN 1: alexandre.bmancebo

GROUP: 3.4                                                            DATE: 06/02/2024
*/
/* Implementation of rational numbers, using a struct */
#include "Rational_struct.h"

// Operation to create a rational number
Rational createRational(int n, int d) {
    Rational r;
    r.num = n;
    r.den = d;
    return r;
}

// Operation that return a numerator of a rational number
int numerator(Rational r) {
    return r.num;
}

// Operation that return a denominator of a rational number
int denominator(Rational r) {
    return r.den;
}

// Operation that return a sum of two rationals
Rational sum(Rational r1, Rational r2) {
    Rational sum;
    sum.num = r1.num * r2.den + r2.num * r1.den;
    sum.den = r1.den * r2.den;
    return sum;
}