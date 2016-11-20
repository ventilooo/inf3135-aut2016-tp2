#include "tp2.h"

char FORMAT[4] = "text";
char *FILENAME;
bool SHOWLANGUAGES = false;
bool SHOWCAPITAL = false;
bool SHOWBORDERS = false;
bool SHOWFLAG = false;
char COUNTRY[3];
char REGION[8];

void getPays(bool showlanguages, bool showcapital, bool showflag, char country[], char region[] );

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
                break;
            case 'c':
                FILENAME =  optarg;
                break;
            case 'd':
                SHOWLANGUAGES = true;
                break;   
            case 'e':
                SHOWCAPITAL = true;
                break;
            case 'f':
                SHOWBORDERS = true;
                break; 
            case 'g':
                SHOWFLAG = true;
                break;   
            case 'h':
                strcpy(COUNTRY, optarg);
                break;
            case 'i':
                strcpy(REGION, optarg);
                break;
        }
    }
}


void help(){
    int c;
    FILE *fHelp;
    fHelp = fopen("../src/help.txt", "r");

    if(fHelp){
        while ((c = getc(fHelp)) != EOF){
            putchar(c);
        }
        fclose(fHelp);
        exit(0);
    }else{
        printf("I/0 Exception\n");
        exit(1);
    }
}

void getPays(bool showlanguages, bool showcapital, bool showflag, char country[], char region[] ){

    

}

void initJson(json_t *objetJson){

    json_t *countries;
    countries = fopen("../data/countries/countries.json", "r");

 if(countries){
        
        json_object_update(objetJson, countries); 
        
        fclose(countries);
        
    }else{
        printf("I/0 Exception\n");
        exit(1);
    }

}
