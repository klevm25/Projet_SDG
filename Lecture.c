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
  *Dist = LectureDist(*nbclients);}

  int main() {
    int nbclient;
    int Q;
    int* quantite;
    double** Dist;
    Lecture(&nbclient,&Q,&Dist,&quantite);

    printf("Le nombre de client est %d \n",nbclient);
    printf("La quantité maximale d'un camion est %d \n",Q);
    
    for (int i=0;i<nbclient;i++) {
      printf("La quantité à livrer pour %d est %d \n",i,quantite[i]);
    }

    int j=0;
    for(int i=0;i<nbclient;i++) {
      for(j=i;j<nbclient;j++) {
        if (i!=j) {
          printf("La distance entre %d et %d est %lf \n",i,j,Dist[i][j]);
        }
      }
    }


    
  }
