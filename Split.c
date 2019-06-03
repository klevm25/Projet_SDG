/* split.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "Split.h"
#include "Lecture.h"
#include "Tour_geant.h"
#include "Solution.h"

void ajouter_en_tete_liste (struct liste* L,double poids, int sommet)
{   struct maillon* nouveau;

    nouveau = (struct maillon*)malloc (sizeof (struct maillon));
    assert (nouveau != NIL);
    nouveau->poids  = poids;
    nouveau->sommet = sommet;  
    nouveau->suivant = L->tete;
    L->tete = nouveau;
    L->nbelem += 1;
}

void Init_Head(struct liste* Head,int nbclient) {
  
    for(int i=0;i<nbclient;i++) {
      Head[i].tete = NIL;
      Head[i].nbelem = 0;
    }
}

void imprimer_liste(struct liste* L) {
struct maillon* M;

    M = L->tete;
    printf("nbelem est %d",L->nbelem);
    while(M != NIL)
    {
      printf(" %f ", M->poids);
      M = M->suivant;

    }
}


void afficher_liste(struct liste* H,int nbclient) {
    for(int i=0;i<nbclient+1;i++) {
      imprimer_liste(&H[i]);
      printf("\n");
    }
}

void clear_liste(struct liste* L) {
    struct maillon* courant;
    struct maillon* suivant;
    int i;

    courant = L->tete;
    for (i = 0; i < L->nbelem; i++)
    {   suivant = courant->suivant;
        free (courant);
        courant = suivant;
    }
    free(courant);
}

struct liste* Split(int* T,int Q,int nbclient, double ** Dist, int* quantite)
{
    int i,j,load;
    double cost;
    struct liste* H;

    H = malloc((nbclient+1)*sizeof(struct liste));
    Init_Head(H,nbclient+1);
    for (i=1;i<=nbclient;i++) {
        j = i;
        load = 0;
        while (j<=nbclient && load < Q) {
            load += quantite[T[j-1]-1];
            if (i==j) {
                cost = Dist[0][T[i-1]] + Dist[T[i-1]][0];
            }
            
            else {
                cost = cost - Dist[T[j-2]][0] + Dist[T[j-2]][T[j-1]] + Dist[T[j-1]][0] ;
                
            }

            if (load <= Q) {
                ajouter_en_tete_liste(&H[i-1],cost,j);
            }
          j++;   
        }
    }
    return H;
}
