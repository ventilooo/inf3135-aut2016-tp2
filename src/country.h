#include "link.h"
#define MAXLENGTHLANGUES 352

int getIndexPays(json_t *objetJson, char* pays, int nombreTotalPays); 
char* getCapitale(json_t *objetJson, int indexPays); 
char* getNomPays(json_t *objetJson, int indexPays);
void getLangues(json_t *objetJson, int indexPays, char* strLangues);
void affichage(bool SHOWCAPITAL, bool SHOWLANGUAGES, bool SHOWFLAG, bool SHOWBORDERS, char country[], char region[]);
