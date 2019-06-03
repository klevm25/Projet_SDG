/* Bellman.c */

#include <stdbool.h>
#include <assert.h>
#include "Bellman.h"
#define MAX_ENTIER 100000000000000

void Bellman(struct liste* H,double** Dist, int* pere,double* pi,int nbclient) {
    int r,i,j,k;
    
    // on choisit 0, qui correspond au dépôt comme racine
    r=0;
    struct maillon* courant= H[r].tete;
    for (k=0; k<=nbclient; k++) {
        pi[k] = MAX_ENTIER;
        pere[k]=r;
    }
    pi[r]=0;
      for(i=0;i<H[r].nbelem;i++) {
        pi[courant->sommet] = courant->poids;
        pere[courant->sommet] = r;
        courant = courant->suivant;
    }

    for (j=1;j<nbclient+1;j++) {
      courant =  H[j].tete;
      for(i=0;i<H[j].nbelem;i++) {
        if(pi[j] + courant->poids < pi[courant->sommet]) {
          pi[courant->sommet] = courant->poids+pi[j];
          pere[courant->sommet] = j;
        }
        courant = courant->suivant;
      }
  }
}