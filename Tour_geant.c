/* Tour_geant.c */

#include "Tour_geant.h"
#include <stdio.h>
#include <stdlib.h>

int RechercheProcheVoisin(double** Dist,int nbclients, int i, bool* mark)
{
  // Declaration
  int k;
  int indi_min;
  double dist_min;


  // Initialisation 
  indi_min = 1;
  while(mark[indi_min-1]==true) { //on cherche un élément non marqué
    indi_min++; }
  dist_min = Dist[i][indi_min];
  
  // Recherche du client non marqué et ayant le potentiel le plus petit
  for(k=indi_min+1;k<=nbclients;k++)
  {
    if((Dist[i][k]!=0)&&(mark[k-1]==false)&&(dist_min>Dist[i][k])) //different d'un élément de diagonale
    {
      dist_min = Dist[i][k];
      indi_min = k;
    }
  }
  
  return indi_min;
}

void TourGeant(int nbclients, double **Dist, int* T)
{
  /* Declaration */
  int k;
  int min;
  bool mark[nbclients];

  
  /* Initialisation */
  for(k=0;k<nbclients;k++)
    mark[k] = false;
  
  // Tour géant
  for(k=1;k<nbclients;k++)
  {
    min = RechercheProcheVoisin(Dist,nbclients,k,mark);
    mark[min-1]=true;
    T[k-1]= min;
  }
}
