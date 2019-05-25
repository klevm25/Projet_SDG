/* split.h */



/* definition de nos structures */
struct liste {
    struct maillon* tete;
    int nbelem; 
};
struct TableSucc {
  int* Head;
  struct liste Succ;
};

struct maillon {
    struct maillon* suivant;
    int sommet;
    int* parcours;
    int poids;
}


/* definition de NIL */

#define NIL (struct maillon*)0
;



/* Prototypes */

extern void Init_TableSucc(struct TableSucc*, int);

extern void Split(int*,int ,int , double** , int*, struct TableSucc* );
extern void ajout_en_tete(struct liste*,int,int,int,int);