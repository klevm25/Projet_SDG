/* split.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Split.h"

int* chemin(int a,int b) {
    int i;
    i = a;
    int* chemin = malloc((b-a)*sizeof(int));
    for (int j=0;j<b-a;j++) {
        chemin[j] = i;
        i++;
    }
    return chemin;
}

void ajout_en_tete(struct liste* L,int poids, int sommet,int client_debut,int client_fin) {
    struct maillon* M;
    M = malloc(sizeof(struct maillon));
    M->poids  = poids;
    M->sommet = sommet;
    M->parcours = chemin(client_debut,client_fin);
    M->suivant = L->tete;

    L->nbelem+=1;
    L->tete = M;
}

void Init_TableSucc(struct TableSucc* H,int nbclients) {
    
    H->Head = (int*)malloc((nbclients+1)*sizeof(int));
    H->Head[0]=0;
    H->Succ.nbelem = 0;
    H->Succ.tete = NIL;
}

void Split(int* T,int Q,int nbclient, double ** Dist, int* quantite,struct TableSucc* H)
{
    int i,j,load;
    double cost;

    for (i=1;i<=nbclient;i++) {
        j = i;
        load = 0;
        while (j>nbclient || load >= Q) {
            load += quantite[j];
            if (i==j) {
                cost = 2*Dist[0][T[j-1]];
            }
            
            else {
                cost = cost - Dist[T[j-1]][0] + Dist[T[j-1]][T[j]] + Dist[T[j]][0] ;
            }

            if (load <= Q) {
                H[i-1].Head[i-1] = i-1;
                ajout_en_tete(&H[i-1].Succ,cost,j,i,j);
            }
            j++;   
        }
    }
}
