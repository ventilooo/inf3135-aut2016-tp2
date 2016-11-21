#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>

/**
 *  * Lis les arguments passes au programme et initialise les parametres 
 *   * qui serviront a l'execution du programme.
 *    *
 *     * @param argc
 *      * @param argv
 *       */
void getOpts(int argc, char *argv[]);
/**
 *  * Imprime a l'ecran le message d'aide et termine le programme.
 *   */
void help();
