/* Bellman.c */

#include <stdbool.h>
#include <assert.h>
#include "Bellman.h"

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
  T[0] = 1;
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

//Sera utiisé pour les tests


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

void ajouter_en_queue_liste(struct liste* L,int poids,int sommet,int client_debut,int client_fin) {
  struct maillon* nouveau;

    nouveau = (struct maillon*)malloc (sizeof (struct maillon));
    assert (nouveau != NIL);
    nouveau->poids  = poids;
    nouveau->sommet = sommet;
    nouveau->parcours = chemin(client_debut,client_fin);
    nouveau->suivant = NIL;

    if(L->nbelem == 0) {
      L->tete = nouveau;
    }

    else {
      struct maillon* M;
      M = L->tete;
      for(int i=0;i<L->nbelem-1;i++) {
        M = M->suivant;
      }
      M->suivant = nouveau;
    }

    L->nbelem ++;
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
                /* printf("ajout_en_queue fait pout %d et %d \n",i-1,j);
                printf("cout entre %d et %d est %lf \n",i-1,j,cost); */
            }
          j++;   
        }
    }
    return H;
}

//pour tester le code

void Bellman(struct liste* H,double** Dist, int* pere,double* pi,int nbclient) {
    int r,i,j,k;
    
    // on choisit 0, qui correspond au dépôt comme racine
    r=0;
    struct maillon* courant= H[r].tete;
    for (k=0; k<=nbclient; k++) {
      printf("Le remplissage de pi et pere est ok \n");
        pi[k] = 10000000;
        pere[k]=r;
    }
    pi[r]=0;
    printf("pi de 0 est bien égale à 0 \n");
      for(i=0;i<H[r].nbelem;i++) {
        pi[courant->sommet] = courant->poids;
        pere[courant->sommet] = r;
        courant = courant->suivant;
    }

    for (j=1;j<nbclient+1;j++) {
      courant =  H[j].tete;
      for(i=0;i<H[j].nbelem;i++) {
        if(pi[j] + courant->poids < pi[courant->sommet]) {
          pi[courant->sommet] = courant->poids+pi[j];
          pere[courant->sommet] = j;
        }
        courant = courant->suivant;
      }
  }
}

int main() {
  int nbclients;
  int Q;
  double** Dist;
  int* quantite;
  int* T;
  int *pere;
  double *pi;
  struct liste* H;
  
  Lecture(&nbclients,&Q,&Dist,&quantite);
  pere = malloc((nbclients)*sizeof(int));
  pi = malloc((nbclients)*sizeof(double));


  T=TourGeant(nbclients,Dist);

  H=Split(T,Q,nbclients,Dist,quantite);
  afficher_liste(H,nbclients);

  Bellman(H,Dist,pere,pi,nbclients);

  for(int i=0;i<nbclients+1;i++) {
      printf("le père de %d est %d \n",i,pere[i]);
      printf("le pi de %d est %f \n",i,pi[i]);
  }

}