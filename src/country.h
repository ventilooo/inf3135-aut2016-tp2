#include "link.h"
#define MAXLENGTHLANGUES 400
#define MAXLENGTHBORDERS 75
#ifndef COUNTRY_H
#define COUNTRY_H

struct Countries_args {
    char *FILENAME;
    char FORMAT[5];
    bool SHOWLANGUAGES;
    bool SHOWCAPITAL;
    bool SHOWBORDERS;
    bool SHOWFLAG;
    bool SHOWCOUNTRY;
    bool SHOWREGION ; 
    char COUNTRY[4];
    char REGION[8];
};

struct region_info {
    int *listeIndexPays;
    int nombrePays ;
};

#endif /* COUNTRY_H */

int getIndexPays(json_t *objetJson, char* pays, int nombreTotalPays);
const char* getCapitale(json_t *objetJson, int indexPays);
const char* getNomPays(json_t *objetJson, int indexPays);
void getLangues(json_t *objetJson, int indexPays, char* strLangues);
void getBorders(json_t *objetJson,int indexPays, char* strBorders);
struct region_info *getPaysMemeRegion(json_t *objetJson, int nombreTotalPays, char* REGION) ; 
void affichage(struct Countries_args *countries, json_t *objetJson ,int nombreTotalPays);
char* getCode(json_t *objetJson,int indexPays);

