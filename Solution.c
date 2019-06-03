#include <stdbool.h>
#include <assert.h>
#include "Bellman.h"
#include "Solution.h"
#include "Split.h"


void ajout_en_tete_sommet(struct liste_sommet* L,int d) {
   struct sommet* nouveau;

    nouveau = (struct sommet*)malloc (sizeof (struct sommet));
    assert (nouveau != (struct sommet*)0);
    nouveau->sommet = d;  
    nouveau->suivant = L->tete;
    L->tete = nouveau;
    L->nbelem += 1;
}

void init_liste_sommet(struct liste_sommet* Solution) {
    Solution->tete = (struct sommet*)0;
    Solution->nbelem = 0;
}

void affiche_liste_sommet(struct liste_sommet* L) {
    struct sommet* M;
    printf ("[");
    M = L->tete;
    for (int i = 0; i < L->nbelem; i++)
    {   if (i == 0)
            printf ("%d", M->sommet);
        else
            printf (", %d", M->sommet);
        M = M->suivant;
    }
    printf ("]\n");
}

void clear_liste_sommet(struct liste_sommet* S)
{
   struct sommet* courant;
    struct sommet* suivant;
    int i;

    courant = S->tete;
    for (i = 0; i < S->nbelem; i++)
    {   suivant = courant->suivant;
/* appeler ici un �ventuel destructeur pour nouveau->value */
        free (courant);
        courant = suivant;
    }
}
struct liste_sommet* Solution(int* pere,double* pi,int nbclients) {
    struct liste_sommet* Solution;
    Solution = (struct liste_sommet*)malloc(sizeof(struct sommet));
    assert(Solution != (struct liste_sommet*)0);
    init_liste_sommet(Solution);
    double dernier_client = nbclients;
    while(dernier_client != 0) {
        ajout_en_tete_sommet(Solution,dernier_client);
        int i = dernier_client;
        dernier_client = pere[i];
    }
    ajout_en_tete_sommet(Solution,0);

    return Solution;
}

double cout_total(double* pi,int nbclients) {
    return pi[nbclients];
}