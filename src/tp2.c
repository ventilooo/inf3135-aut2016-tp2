#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
int main(int argc, char *argv[]){
    
    char format[];
    char fileName[];
    bool languages = false;
    bool capital = false;
    bool borders = false;
    bool flag = false;
    char country;
    char region;

    int retOpt;


    while (retOpt = getopt(int argc, char * const argv[], const char *optstring) != -1){

        switch(retOpt){

            case('help'):
                help();
                return 0;
            case('output-fromat'):
                format = optstring;
                break;
            case('output-filename'):

                break;
            case('show-languages'):

                break;
            case('show-capital'):

                break;
            case('show-borders'):

                break;
            case('show-flag'):

                break;
            case('country'):

                break;
            case('region'):

                break;
        }
        
        printf("%c\n", format);

        return 0; 

    }




}


}

//Imprime a l'ecran le message d'aide et termine le programme.
void help(){



}
