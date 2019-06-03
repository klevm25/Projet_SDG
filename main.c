/* main.c */

#include<stdio.h>
#include<stdlib.h>
#include "Lecture.h"
#include "Tour_geant.h"
#include "Split.h"
#include "Bellman.h"
#include "Solution.h"

int main() {
  int nbclients,Q,sommet_initial;
  double** Dist;
  int* quantite; 
  int* T;
  struct liste* H;
  int *pere;
  double *pi;
  struct liste_sommet* S;
  
  Lecture(&sommet_initial,&nbclients,&Q,&Dist,&quantite);

  T=TourGeant(nbclients,Dist,sommet_initial);
  H=Split(T,Q,nbclients,Dist,quantite);

  pere = malloc((nbclients+1)*sizeof(int));
  pi = malloc((nbclients+1)*sizeof(double)); 

  //afficher_liste(H,nbclients);

  Bellman(H,Dist,pere,pi,nbclients);

  S = Solution(pere,pi,nbclients);
  printf("Le tour géant commence avec le client %d\n",sommet_initial);
  printf("Le coût total de livraison est %f \n",cout_total(pi,nbclients));
  printf("Les sommets parcourus sont : \n");
  affiche_liste_sommet(S);
  printf("Pour réaliser la livraison nous avons besoin de %d camions \n",S->nbelem-1);

  free(quantite);
  for(int i=0;i<nbclients;i++) {
    free(Dist[i]);
    clear_liste(&H[i]);
  }
  free(Dist);
  clear_liste(&H[nbclients]);
  free(pere);
  free(pi);
   
  clear_liste_sommet(S);
  
  free(T);

  return 0;
}
