#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
/**
 * Lis les arguments passes au programme et initialise les parametres 
 * qui serviront a l'execution du programme.
 *
 * @param argc
 * @param argv
 */
void getOpts(int argc, char *argv[]);
void help();

   char FORMAT[4] = "text";
   char *FILENAME;
   bool SHOWLANGUAGES = false;
   bool SHOWCAPITAL = false;
   bool SHOWBORDERS = false;
   bool SHOWFLAG = false;
   char COUNTRY[3];
   char REGION[8];
   
int main(int argc, char *argv[]){
    getOpts(argc,argv);
    return 0;
}

void getOpts(int argc, char *argv[]){

    int option;
    int index;
    static struct option long_opts[] =
    {
        {"help",     no_argument,       0, 'a'},
        {"output-format",  required_argument,       0, 'b'},
        {"output-filename",  required_argument, 0, 'c'},
        {"show-languages",   no_argument,  0, 'd'},
        {"show-capital",   no_argument, 0, 'e'},
        {"show-borders",    no_argument, 0, 'f'},
        {"show-flag",    no_argument, 0, 'g'},
        {"country",    required_argument, 0, 'h'},
        {"region",    required_argument, 0, 'i'},

    };

    while ((option = getopt_long(argc, argv, "ab:c:defgh:i:", long_opts, &index)) != -1) {

        switch (option){

            case 'a':
                help();
                break;
            case 'b':
                strcpy(FORMAT, optarg);
                printf("%s", FORMAT);
                break;
            case 'c':
                
                break;
            case 'd':

                break;   
            case 'e':

                break;
            case 'f':

                break; 
            case 'g':

                break;   
            case 'h':

                break;
            case 'i':

                break;
        }
    }
}

//Imprime a l'ecran le message d'aide et termine le programme.
void help(){
    int c;
    FILE *fHelp;
    fHelp = fopen("help.txt", "r");

    if(fHelp){
        while ((c = getc(fHelp)) != EOF){
            putchar(c);
        }
        fclose(fHelp);
        exit(0);
    }else{
        printf("I/0 Exception");
        exit(1);
    }
}



