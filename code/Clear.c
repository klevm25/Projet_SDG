#include <stdio.h>
#include <stdlib.h>
#include "Split.h"
#include "Solution.h"
#include "Clear.h"

void clear_donnee(int* quantite,double** Dist,int* T,struct liste* H,int* pere,double* pi,struct liste_sommet* S,int nbclients) {
    free(quantite);
  for(int i=0;i<=nbclients;i++) {
    free(Dist[i]);
    clear_liste(&H[i]);
  }
  free(Dist);
  free(H);
  
  free(pere);
  free(pi);
   
  clear_liste_sommet(S);
  free(S);
  
  free(T);
}