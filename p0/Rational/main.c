/*
TITLE: PROGRAMMING II LABS                   SUBTITLE: P0

AUTHOR 1: Alexandre Borrazás Mancebo LOGIN 1: alexandre.bmancebo

AUTHOR 2: Carlos Losada Gómez LOGIN 2: carlos.lgomez

GROUP: 3.4                                                            DATE: 06/02/2024
*/
#include <stdio.h>
#include "Rational_struct.h"
//#include "Rational_pointer.h"

int main() {
    Rational r1, r2, r3, r4, s;

    r1 = createRational(2, 3);
    r2 = createRational(5, 7);
    r3 = createRational(7, 3);
    r4 = createRational(5, 4);
    s = sum(r1, r2);
    printf("\nThe sum is:%d/%d\n\n", numerator(s), denominator(s));
    s = sum(r3, r4);
    printf("\nThe sum is:%d/%d\n\n", numerator(s), denominator(s));
    return 0;
}