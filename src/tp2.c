#include "tp2.h"

char FORMAT[4] = "text";
char *FILENAME;
bool SHOWLANGUAGES = false;
bool SHOWCAPITAL = false;
bool SHOWBORDERS = false;
bool SHOWFLAG = false;
char COUNTRY[4];
char REGION[8];
int indexPays ; 
char *capitale ; 
char *nomPays ; 

void getOpts(int argc, char *argv[]) ; 
void help() ; 
int getIndexPays(json_t *objetJson, char* pays, int nombreTotalPays ) ; 
char* getCapitale(json_t *objetJson, int indexPays) ; 
char* getNomPays(json_t *objetJson, int indexPays) ;
void printLangues (json_t *objetJson, int indexPays) ;
void affichage(bool SHOWCAPITAL, bool SHOWLANGUAGES, bool SHOWFLAG, bool SHOWBORDERS, char country[], char region[] );


int main(int argc, char *argv[]){

    //Récupération des arguments
    getOpts(argc,argv);
    
    //Init objet Json du dossier data 
    json_t *objetJson ; 
    objetJson = json_load_file("../data/countries/countries.json", 0, NULL);
    
    // Récupération du nombre total de pays
    int nombreTotalPays = json_array_size(objetJson);
    // printf("Nombre total pays : %d\n",nombreTotalPays);
 
    // Récupération de l'index du pays en fonction du nom récupéré
    indexPays = getIndexPays(objetJson,COUNTRY,nombreTotalPays) ; 
    
    // Récupération de la capitale du pays en question 
     capitale = getCapitale(objetJson, indexPays) ; 
    
    // Récupération du nom du pays 
     nomPays = getNomPays(objetJson, indexPays) ; 
    
    // Affichage des langues
    printLangues(objetJson, indexPays) ; 
    
    printf(" Abréviation 3 lettres : %s \n", COUNTRY) ;
    printf(" Index : %d \n" , indexPays) ; 
    printf(" Capitale : %s \n", capitale) ; 
    printf(" Nom Pays : %s \n", nomPays) ; 
    
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


int getIndexPays(json_t *objetJson, char* pays, int nombreTotalPays) {

	int indexPays = 0  ; 
	json_t *paysCible ; 
	json_t *ciocPays ; 
	char *ciocCorrespondant ;
	int i ; 
	
	
	for ( i = 0 ; i < nombreTotalPays ; i++ ) {
	
		paysCible = json_array_get(objetJson, i);
		ciocPays = json_object_get(paysCible,"cioc");
		ciocCorrespondant = json_string_value(ciocPays) ;
		if ( strcasecmp(pays, ciocCorrespondant) == 0 ) {
			indexPays = i ;
		}
		
	}
	
	return indexPays ; 
	
}

char* getCapitale(json_t *objetJson, int indexPays) {
	
	 json_t *paysCible;
	 json_t *valeurCapitale ; 
	
	 paysCible = json_array_get(objetJson, indexPays);
     valeurCapitale = json_object_get(paysCible, "capital");
     char *capitale = json_string_value(valeurCapitale);
     
     return capitale ;

}

char* getNomPays(json_t *objetJson, int indexPays) {

	json_t *paysCible;
	json_t *nomsDuPays ;
	json_t *nomCommun;
	
	paysCible = json_array_get(objetJson, indexPays);
	nomsDuPays = json_object_get(paysCible,"name");  
	nomCommun = json_object_get(nomsDuPays,"common");
    char *nomCommunPays = json_string_value(nomCommun);
    
    return nomCommunPays ;
	
}

 void printLangues (json_t *objetJson, int indexPays) {

	json_t *paysCible; 
	json_t *languesDuPays ; 
	const char *key;
    json_t *value;
	
	paysCible = json_array_get(objetJson, indexPays) ; 
	languesDuPays = json_object_get(paysCible,"languages");
	printf("Languages: ");
	json_object_foreach(languesDuPays, key, value) {
		printf("%s, ",json_string_value(value)) ; 
	}

	printf("\n");


}



void affichage(bool SHOWCAPITAL, bool SHOWLANGUAGES, bool SHOWFLAG, bool SHOWBORDERS, char country[], char region[] ){ 
	
	if ( SHOWCAPITAL ) {
		
	}  
	
	if ( SHOWLANGUAGES ) {
		
	}
	
	if ( SHOWBORDERS ) {
	
	}
	

}



