/* main.c */

#include<stdio.h>
#include<stdlib.h>
#include "Lecture.h"
#include "Tour_geant.h"
#include "Split.h"
#include "Bellman.h"

int main()
{
  //Declaration
  int nbclients;
  int Q;
  double** Dist;
  int* quantite;
  int* pere;
  double* pi;
  int* tour_geant;
  struct liste* H;
  int i;

  
  //Lecture
  Lecture(&nbclients,&Q,&Dist,&quantite);
  
  //Tour Geant
  tour_geant = TourGeant(nbclients, Dist);

  //Creation du sous graphe auxiliaire
  H = Split(tour_geant, Q, nbclients, Dist, quantite);

  //Plus court chemin
  pere = (int*)malloc(nbclients*sizeof(int));
  pi = (double*)malloc(nbclients*sizeof(double));
  Bellman(H,Dist,pere,pi,nbclients);


  //Calcul et affichage du cout
  //printf("Cout total : %lf\n", calcul_cout(solution, nbliste, Dist));
  
 
  //Liberation de la memoire
  
  //Donnees
  free(quantite);
  for(i=0;i<=nbclients;i++)
    free(Dist[i]);
  free(Dist);
  
  //Tour Geant
  free(tour_geant);
  
  //Sous graphe auxiliaire
  //clear_liste(H);
  
  
  return 0;
}
