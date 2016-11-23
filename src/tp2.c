#include "tp2.h"
#include "country.h"
/*
struct Countries_args {
    char *FILENAME;
    char FORMAT[4];
    bool SHOWLANGUAGES;
    bool SHOWCAPITAL;
    bool SHOWBORDERS;
    bool SHOWFLAG;
    bool SHOWCOUNTRY;
    bool SHOWREGION ; 
    char COUNTRY[4];
    char REGION[8];
};
*/
//int indexPays; 
//char *capitale; 
//char *nomPays;

int main(int argc, char *argv[]){

	//Init objet Json du dossier data 
    json_t *objetJson ; 
    objetJson = json_load_file("../data/countries/countries.json", 0, NULL);
       
    // Récupération du nombre total de pays du fichier Json : 
    int nombreTotalPays = json_array_size(objetJson);
    
    //Récupération des arguments passés à l'execution : 
    struct Countries_args *countries = getOpts(argc,argv);


    
   
    //char strBorders[MAXLENGTHBORDERS];
    //getBorders(objetJson, indexPays, strBorders); 
    //printf("Borders : "); 
    //printf("%s", strBorders) ; 
    //printf("\n"); 
    
    affichage(countries, objetJson, nombreTotalPays) ; 
    
    // Tableau des fichiers de la meme region 
    
    struct region_info *r = getPaysMemeRegion(objetJson ,nombreTotalPays, countries->REGION) ;
    
    int i ;
    for ( i = 0 ; i <  r->nombrePays ; i++ ) {
    	printf("%d Pays : %d \n" ,i, r->listeIndexPays[i]) ; 
    }
     
    return 0;
}

struct Countries_args *getOpts(int argc, char *argv[]){

    struct Countries_args *p = malloc(sizeof(struct Countries_args));

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
                strcpy(p->FORMAT, optarg);
                break;
            case 'c':
                p->FILENAME =  optarg;
                break;
            case 'd':
                p->SHOWLANGUAGES = true;
                break;   
            case 'e':
                p->SHOWCAPITAL = true;
                break;
            case 'f':
                p->SHOWBORDERS = true;
                break; 
            case 'g':
                p->SHOWFLAG = true;
                break;   
            case 'h':
                p->SHOWCOUNTRY = true;
                strcpy(p->COUNTRY, optarg);
                break;
            case 'i':
            	p->SHOWREGION = true;
                strcpy(p->REGION, optarg);
                break;
        }
    }
    return p;
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



