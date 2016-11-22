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
void getPays(bool showlanguages, bool showcapital, bool showflag, char country[], char region[] );


int main(int argc, char *argv[]){

    //Récupération des arguments
    getOpts(argc,argv);
    
    //Init objet Json du dossier data 
    json_t *objetJson ; 
    objetJson = json_load_file("../data/countries/countries.json", 0, NULL);
    
    // Récupération du nombre total de pays
    int nombreTotalPays = json_array_size(objetJson);
    printf("Nombre total pays : %d",nombreTotalPays);
 
    // Récupération de l'index du pays en fonction du nom récupéré
    indexPays = getIndexPays(objetJson,COUNTRY,nombreTotalPays) ; 
    
    // Récupération de la capitale du pays en question 
    capitale = getCapitale(objetJson, indexPays) ; 
    
    // Récupération du nom du pays 
    nomPays = getNomPays(objetJson, indexPays) ; 
    
    
    printf(" Abréviation 3 lettres : %s \n", COUNTRY) ;
    printf(" Index : %d \n" , indexPays) ; 
    //printf(" Capitale : %s \n", capitale) ; 
    //printf(" Nom Pays : %s \n", nomPays) ; 
    
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
                usage();
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


void usage(){
    fprintf(stderr,
            "Usage: bin/tp2 [--help] [--output-format FORMAT] [--output-filename FILENAME]\n"
            " [--show-languages] [--show-capital] [--show-borders] [--show-flag]\n"
            " [--country COUNTRY] [--region REGION]\n"
            "\nDisplays informations about countries.\n"
            "\nOptional arguments:\n"
            "    --help Show                this help message and exit.\n"  
            "    --output-format FORMAT     Selects the ouput format (either \"text\", \"dot\" or \"png\").\n"
            "                               The \"dot\" format is the one recognized by Graphviz.\n"
            "                               The default format is \"text\".\n"
            "    --output-filename FILENAME The name of the output filename. This argument is\n"
            "                               mandatory for the \"png\" format. For the \"text\" and \"dot\"\n"
            "                               format, the result is printed on stdout if no output\n"
            "                               filename is given.\n"
            "    --show-languages           The official languages of each country are displayed.\n"
            "    --show-capital             The capital of each country is displayed.\n"
            "    --show-borders             The borders of each country is displayed.\n"
            "    --show-flag                The flag of each country is displayed.\n"
            "                               (only for \"dot\" and \"png\" format).\n"
            "    --country COUNTRY          The country code (e.g \"can\", \"usa\") to ble displayed.\n"
            "    --region REGION            The region of the countries to displayed.\n"
            "                               The supported regions are \"africa\", \"americas\",\n"
            "                               \"asia\", \"europe\" and \"oceania\".\n"
            "\n");
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
	
	return "";

}

char* getNomPays(json_t *objetJson, int indexPays) {

	return ""; 
	
}


void getPays(bool showlanguages, bool showcapital, bool showflag, char country[], char region[] ){   

}

