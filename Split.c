/* split.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "Split.h"
#include "Lecture.h"
#include "Tour_geant.h"




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


void ajouter_en_tete_liste (struct liste* L,int poids, int sommet,int client_debut,int client_fin)
{   struct maillon* nouveau;

    nouveau = (struct maillon*)malloc (sizeof (struct maillon));
    assert (nouveau != NIL);
    nouveau->poids  = poids;
    nouveau->sommet = sommet;
    nouveau->parcours = chemin(client_debut,client_fin);  
    nouveau->suivant = L->tete;
    L->tete = nouveau;
    L->nbelem += 1;
}

void Init_Head(struct liste* Head,int nbclient) {
    for(int i=0;i<nbclient+1;i++) {
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
      printf(" %d ", M->poids);
      M = M->suivant;

    }
}


void afficher_liste(struct liste* H,int nbclient) {
    for(int i=0;i<nbclient+1;i++) {
      printf("Le sommet est %d \t",i);
      imprimer_liste(&H[i]);
      printf("\n");
    }
}

struct liste* Split(int* T,int Q,int nbclient, double ** Dist, int* quantite)
{
    int i,j,load;
    double cost;
    struct liste* H;

    H = malloc((nbclient+1)*sizeof(struct liste));
    Init_Head(H,nbclient);
    printf("Initialisation faite \n");
    for (i=1;i<=nbclient;i++) {
        j = i;
        load = 0;
        printf("Load chargé \n");
        while (j<=nbclient && load < Q) {
          printf("i vaut %d et j vaut %d \n",i,j);
            load += quantite[T[j-1]-1];
            if (i==j) {
                cost = 2*Dist[0][T[i-1]];
            }
            
            else {
                cost = cost - Dist[T[j-2]][0] + Dist[T[j-2]][T[j-1]] + Dist[T[j-1]][0] ;
                
            }

            if (load <= Q) {
                ajouter_en_tete_liste(&H[i-1],cost,j,i-1,j);
                printf("ajout_en_queue fait pout %d et %d \n",i-1,j);
                printf("cout entre %d et %d est %lf \n",i-1,j,cost);
            }
          j++;   
        }
    }
    return H;
}
