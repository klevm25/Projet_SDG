/* split.h */

#if ! defined (SPLIT_H)
#define SPLIT_H 1

/* definition de nos structures */
struct maillon {
    struct maillon* suivant;
    int sommet;
    //int* parcours;
    double poids;
};

struct liste {
    struct maillon* tete;
    int nbelem; 
};


/* definition de NIL */

#define NIL (struct maillon*)0
;



/* Prototypes */

extern void Init_Head(struct liste*, int);
extern struct liste* Split(int*,int ,int , double** , int*);
extern void afficher_liste(struct liste*,int);
extern void clear_liste(struct liste*);
#endif