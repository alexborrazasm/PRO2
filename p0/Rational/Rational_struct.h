/*
TITLE: PROGRAMMING II LABS                   SUBTITLE: P0

AUTHOR 1: Alexandre Borrazás Mancebo LOGIN 1: alexandre.bmancebo

AUTHOR 2: Carlos Losada Gómez LOGIN 2: carlos.lgomez

GROUP: 3.4                                                            DATE: 06/02/2024
*/
#ifndef RATIONAL_RATIONAL_STRUCT_H
#define RATIONAL_RATIONAL_STRUCT_H

typedef struct Data Rational;
struct Data {
    int num;
    int den;
};

Rational createRational(int n, int d);
int numerator(Rational r);
int denominator(Rational r);
Rational sum(Rational r1, Rational r2);

#endif //RATIONAL_RATIONAL_STRUCT_H
