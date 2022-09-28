/* 28-02-2022 */
/* alex */
/* bchc.c */
#include <stdio.h>
#include <stdlib.h>
#include "bchc.h"

void metode_setABA9(int s, double * cofs, double * res, int depth) {
  int i;
  for (i = 0; i < TAMBCH; i++)
    res[i] = 0.0;
  if (s % 2 == 1)
    res[1] = cofs[s];
  else
    res[0] = cofs[s];
  for (i = s - 1; i >= 0; i--)
    recAB9(res, cofs[i], depth, i);    
}

/* no provat. hi ha que provar si aquest procediment funciona correctament */
void metode_setBAB9(int s, double * cofs, double * res, int depth) {
  int i;
  for (i = 0; i < TAMBCH; i++)
    res[i] = 0.0;
  if (s % 2 == 1)
    res[0] = cofs[s];
  else
    res[1] = cofs[s];
  for (i = s - 1; i >= 0; i--)
    recAB9(res, cofs[i], depth, i + 1);    
}

void metode_setSCABA9(int s, double complex * cofs, double * res, int depth) {
  int i;
  for (i = 0; i < TAMBCH; i++)
    res[i] = 0.0;
  if (s % 2 == 1)
    res[1] = creal(cofs[s]);
  else
    res[0] = creal(cofs[s]);
  for (i = s - 1; i >= 0; i--)
    recSCAB9(res, creal(cofs[i]), cimag(cofs[i]), depth, i);
}

void metode_setSCBAB9(int s, double complex * cofs, double * res, int depth) {
  int i;
  for (i = 0; i < TAMBCH; i++)
    res[i] = 0.0;
  if (s % 2 == 1)
    res[0] = creal(cofs[s]);
  else
    res[1] = creal(cofs[s]);
  for (i = s - 1; i >= 0; i--)
    recSCAB9(res, creal(cofs[i]), cimag(cofs[i]), depth, i + 1);
}
