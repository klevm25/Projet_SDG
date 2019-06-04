/* Solution.h */


/* Structure */
struct sommet {
    struct sommet* suivant;
    int sommet;
};

struct liste_sommet {
    struct sommet* tete;
    int nbelem;
};

/* Prototype */

extern struct liste_sommet* Solution(int*,double*,int);
extern void clear_liste_sommet(struct liste_sommet*);
extern void affiche_liste_sommet(struct liste_sommet*);
extern double cout_total(double*,int);
extern void affiche_solution(struct liste_sommet*,struct liste*,int*);