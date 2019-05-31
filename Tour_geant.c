/* Tour_geant.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Tour_geant.h"



#include "Lecture.h"

int * LectureQuantite(int nbclients)
{
  //Declaration
  int i;
  int *quantite;
  
  //allocation dynamique de quantite
  quantite = (int*)malloc(nbclients*sizeof(int));
  
  //Remplissage de quantite
  for(i=0;i<nbclients;i++)
    scanf("%d",&(quantite[i]));
  
  return quantite;
}

double ** LectureDist(int nbclients)
{
  //Declaration
  int i,j;
  double** Dist;
  
  //allocation dynamique de Dist
  Dist=(double**)malloc((nbclients+1) * sizeof(double *)); //ok
  for(i=0;i<nbclients+1;i++)
  {
    Dist[i]=(double *)malloc((nbclients+1)*sizeof(double));
  }
  
  //Remplissage de Dist
  for(i=0;i<nbclients+1;i++)
  {
   for(j=0;j<nbclients+1;j++)
   {
    scanf("%lf",&Dist[i][j]);
   }
  }
  
  return Dist;
}

void Lecture(int *nbclients,int *Q,double*** Dist,int** quantite)
{
  //Lecture de nbclients et Q
  scanf("%d",nbclients);
  scanf("%d",Q);

  //Lecture de quantite
  *quantite = LectureQuantite(*nbclients);
  
  //Lecture de Dist
  *Dist = LectureDist(*nbclients);
  }
//Ici on lit nos données

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

int* TourGeant(int nbclients, double **Dist)
{
  /* Declaration */
  int k;
  int min;
  bool mark[nbclients+1];

  int *T = (int*) malloc(nbclients*sizeof(int));

  
  /* Initialisation */
  for(k=0;k<nbclients;k++)
    mark[k] = false;

  //On choisit de commencer par le sommet 1
  T[0] = 4;
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

int main() {
  int nbclients;
  int Q;
  double** Dist;
  int* quantite;
  int* T;

  Lecture(&nbclients,&Q,&Dist,&quantite);

  T=TourGeant(nbclients,Dist);

  for(int i=0;i<nbclients;i++) {
    printf("%d ",T[i]); 
  }

}
