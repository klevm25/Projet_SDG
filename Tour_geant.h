/* tour_geant.h */
/* Inclusion des bibliotheques */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/* Prototype */

extern void TourGeant(int nbclients, double **Dist,int* T);

extern int RechercheProcheVoisin(double** Dist,int nbclients, int i, bool* mark);


