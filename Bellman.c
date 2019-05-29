/* Bellman.c */
#include <stdbool.h>
#include "Bellman.h"

void Bellman(struct liste* H,double** Dist, int* pere,double* pi,int nbclient) {
    int r,i,j,k;
    // on choisit 0, qui correspond au dépôt comme racine
    r=0;
    struct maillon* courant= H[r].tete;
    for (k=0; k<=nbclient; k++) {
        pi[k] = 10000000;
        pere[k]=0;
    }
    pi[r]=0;

    for(i=0; i < H[r].nbelem;i++) {
        pi[courant->sommet+1] = Dist[r][courant->sommet +1];
        pere[courant->sommet +1] = r;
        courant = courant->suivant;
    }

    for (i=1;i<nbclient+1;i++) {
        for (j=0; j < H[i].nbelem;j++) {
            if (pi[i]+Dist[i][courant->sommet] < pi[courant->sommet]) {
                pi[courant->sommet] = pi[i]+Dist[i][courant->sommet];
                pere[courant->sommet] = i;
                courant = courant->suivant;
            }
        }
    }
}