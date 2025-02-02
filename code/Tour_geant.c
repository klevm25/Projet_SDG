/* Tour_geant.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Tour_geant.h"


int RechercheProcheVoisin(double** Dist,int nbclients, int i, bool* mark)
{
  // Declaration
  int k;
  int indi_min;
  double dist_min;


  // Initialisation 
  indi_min = 1;
  while(mark[indi_min]==true) { //on cherche un élément non marqué
    indi_min++; }
  dist_min = Dist[i][indi_min];
  
  // Recherche du client non marqué et ayant le potentiel le plus petit
  for(k=indi_min+1;k<=nbclients;k++)
  {
    if((Dist[i][k]!=0)&&(mark[k]==false)&&(dist_min>Dist[i][k])) //different d'un élément de diagonale
    {
      dist_min = Dist[i][k];
      indi_min = k;
    }
  }
  
  return indi_min;
}

int* TourGeant(int nbclients, double **Dist,int sommet_initial)
{
  /* Declaration */
  int k;
  int min;
  bool mark[nbclients+1];
  
  /* Initialisation */
  int *T = (int*) malloc((nbclients+1)*sizeof(int));
  for(k=0;k<nbclients;k++)
    mark[k] = false;


  T[0] = sommet_initial;
  mark[T[0]] = true;
  
  // Tour géant
  for(k=0;k<nbclients;k++)
  {
    min = RechercheProcheVoisin(Dist,nbclients,T[k],mark);
    mark[min]=true;
    T[k+1]= min;
  }

  return T;
}
