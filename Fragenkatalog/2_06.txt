/*

Folie 95 (für Herleitung) und Folie 96 in numerical.pdf für Lösung.

*/

#include<stdio.h>
#include<math.h>

unsigned long res = (unsigned long) exp(lgamma(n+1) - lgamma(k+1) - lgamma(n-l+1));

