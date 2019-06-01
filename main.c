/* main.c */

#include<stdio.h>
#include<stdlib.h>
#include "Lecture.h"
#include "Tour_geant.h"
#include "Split.h"
#include "Bellman.h"
#include "Solution.h"

int main() {
  int nbclients;
  int Q;
  double** Dist;
  int* quantite; 
  int* T;
  struct liste* H;
  int *pere;
  double *pi;
  struct liste_sommet* S;
  
  Lecture(&nbclients,&Q,&Dist,&quantite);
  T=TourGeant(nbclients,Dist);
  H=Split(T,Q,nbclients,Dist,quantite);

  pere = malloc((nbclients)*sizeof(int));
  pi = malloc((nbclients)*sizeof(double)); 

  //afficher_liste(H,nbclients);

  Bellman(H,Dist,pere,pi,nbclients);

  S = Decodage(pere,pi,nbclients);
  printf("Le coût total de livraison est %f \n",cout_total(pi,nbclients));
  printf("Les sommets parcourus sont : \n");
  affiche_liste_sommet(S);
  printf("Pour réaliser la livraison nous avons besoin de %d camions \n",S->nbelem-1);

  free(quantite);
  free(pere);
  free(pi);
  for(int i=0;i<nbclients;i++) {
    free(Dist[i]);
    clear_liste(&H[i]);
  }
  free(Dist); 
  clear_liste(&H[nbclients]);
  clear_liste_sommet(S);
  
  free(T); 

  return 0;
}
