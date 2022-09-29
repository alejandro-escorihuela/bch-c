/* 28-02-2022 */
/* alex */
/* recur.h */
#ifndef _RECUR_H
#define _RECUR_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <complex.h>
#define TAMBCH 128

void copyesq(double * dest, double * orig);

void recAB9(double * res, double x, int depth, int b);
void recA9(double * res, double x, int depth);
void recB9(double * res, double x, int depth);

void recSCAB9(double * res, double xre, double xim, int depth, int b);
void recSCA9(double * res, double xre, double xim, int depth);
void recSCB9(double * res, double xre, double xim, int depth);

#endif
