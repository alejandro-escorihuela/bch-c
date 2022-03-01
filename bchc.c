/* 28-02-2022 */
/* alex */
/* bchc.c */
#include <stdio.h>
#include <stdlib.h>
#include "bchc.h"

void metode_setABA9(int num_cofs, double * cofs, double * res, int depth) {
  int i;
  for (i = 0; i < TAMBCH; i++)
    res[i] = 0.0;
  res[1] = cofs[num_cofs/2];
  for (i = num_cofs/2 - 1; i >= 0; i--)
    recAB9(res, cofs[i], depth, i);
}

void metode_setBAB9(int num_cofs, double * cofs, double * res, int depth) {
  int i;
  for (i = 0; i < TAMBCH; i++)
    res[i] = 0.0;
  res[0] = cofs[num_cofs/2];
  for (i = num_cofs/2 - 1; i >= 0; i--)
    recAB9(res, cofs[i], depth, i + 1);
}
