/* Solution.c */

#include "Solution.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* chemin(int a,int b) {
    int i;
    i = a+1;
    int* chemin = malloc((b-a)*sizeof(int));
    for (int j=0;j<abs(b-a);j++) {
        chemin[j] = i;
        i++;
    }
    return chemin;
}

int main() {
  for (int i=0;i<sizeof(chemin(0,2));i++) {
        printf("%d,",(chemin(0,2))[i]);
      }
  //printf("\n %d",sizeof(chemin(0,2)));
}


double calcul_cout(double*pi)
{ 
  return pi[sizeof(pi)-1];
} 

void resultat(int* pere,double* pi) {
    for(int j=1;j<sizeof(pere);j++) {
      printf("{");
      for (int i=0;i<sizeof(chemin(0,2));i++) {
        printf("%d,",(chemin(pere[j],j))[i]);
      }
      printf("}");
    }
} 
