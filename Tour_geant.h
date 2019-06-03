/* Tour_geant.h */
#if ! defined (TOUR_GEANT_H)
#define TOUR_GEANT_H 1


/* Inclusion des bibliotheques */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/* Prototype */

extern int* TourGeant(int, double **,int);

extern int RechercheProcheVoisin(double**,int, int, bool*);

#endif


