/* main.c */

#include<stdio.h>
#include<stdlib.h>
#include "Lecture.h"
#include "Tour_geant.h"
#include "Split.h"
#include "Bellman.h"
#include "Solution.h"
#include "Clear.h"

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

  Bellman(H,Dist,pere,pi,nbclients);

  S = Solution(pere,pi,nbclients);

  printf("Le tour géant commence avec le client %d\n",sommet_initial);
  printf("Le coût total de livraison est %f \n",cout_total(pi,nbclients));
  /*printf("Les sommets parcourus dans le graphe H sont : ");
  affiche_liste_sommet(S); */
  printf("\n");
  affiche_solution(S,H,T);
  printf("\n");
  printf("Pour réaliser la livraison nous avons besoin de %d camions \n",S->nbelem-1);

  clear_donnee(quantite,Dist,T,H,pere,pi,S,nbclients);

  return 0;
}
