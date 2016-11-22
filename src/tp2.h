#include "link.h"

/**
 * Lis les arguments passes au programme et initialise les parametres 
 * qui serviront a l'execution du programme.
 *
 * @param argc
 * @param argv
 */
struct Countries_args *getOpts(int argc, char *argv[]);

/*
 * Imprime a l'ecran le message d'aide et termine le programme.
*/
void usage();
