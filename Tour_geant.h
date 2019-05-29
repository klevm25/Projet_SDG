/* tour_geant.h */
#if ! defined (TOUR_GEANT_H)
#define TOUR_GEANT_H 1
/* Inclusion des bibliotheques */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/* Prototype */

extern int* TourGeant(int nbclients, double **Dist);

extern int RechercheProcheVoisin(double** Dist,int nbclients, int i, bool* mark);

#endif


