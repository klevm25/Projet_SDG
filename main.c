#include "Bellman.h"
#include "Solution.h"
#include "Split.h"
#include "Tour_geant.h"

int main()
{
  //Declaration
  int nbclients;
  int Q;
  double** Dist;
  int* quantite,T,pi;
  struct TableSucc* H;
  int i;


  //Lecture
  Lecture(&nbclients,&Q,&Dist,&quantite);

  //Tour Geant
  TourGeant(nbclients, Dist,T);

  //Création du sous graphe auxiliaire
  Split(T, Q, nbclients, Dist, quantite,H);


  //Calcul et affichage du cout
  printf("Cout total : %lf\n", calcul_cout(pi));

  /* printf("Le chemin emprunté est : %d",);
  printf("Il faut donc : %d voitures",); */


  //Liberation de la memoire

  //Les donnees
  free(quantite);

  for(i=0;i<=nbclients;i++)
    free(Dist[i]);
  free(Dist);

  //Tour Geant
  free(T);

  //La structure
  clear_structure(H);

  return 0;
}