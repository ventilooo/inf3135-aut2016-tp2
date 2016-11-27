#include "country.h"

FILE * initGraphFile();
void closeGraphFile(FILE *fGraph);
void addPays(struct json_t *objetJson, FILE *fGraph, int indexPays, bool capital, bool languages, bool borders);
void languagesOut(struct json_t *objetJson, FILE *fGraph, int indexPays, bool languages);
void capitalOut(struct json_t *objetJson, FILE *fGraph, int indexPays, bool capital);
void bordersOut(struct json_t *objetJson, FILE *fGraph, int indexPays, bool borders);
void regionOut(struct json_t *objetJson, int nombreTotalPays, char * filename, struct Countries_args *countries);
void frontieresOut(struct json_t frontieres, int indexPays);
void paysOut(struct json_t *objetJson, char * filename,int indexPays, struct Countries_args *countries);
void affichageDot();
void enregistrerDot(char * filename, char* FORMAT) ; 
void graphviz(char * filename);
void mergeBordersTofGraph(FILE *fGraph, FILE *borders);