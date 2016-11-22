#include "tp2.h"
#include "country.h"
#define MAXLENGTH 352

struct Countries_args {
    char *FILENAME;
    char FORMAT[4];
    bool SHOWLANGUAGES;
    bool SHOWCAPITAL;
    bool SHOWBORDERS;
    bool SHOWFLAG;
    char COUNTRY[4];
    char REGION[8];
};

int indexPays; 
char *capitale; 
char *nomPays;

int main(int argc, char *argv[]){

    //Récupération des arguments
    struct Countries_args *countries_args = getOpts(argc,argv);
    
    //Init objet Json du dossier data 
    json_t *objetJson ; 
    objetJson = json_load_file("../data/countries/countries.json", 0, NULL);
    
    // Récupération du nombre total de pays
    int nombreTotalPays = json_array_size(objetJson);
    // printf("Nombre total pays : %d\n",nombreTotalPays);
 
    // Récupération de l'index du pays en fonction du nom récupéré
    indexPays = getIndexPays(objetJson,countries_args->COUNTRY,nombreTotalPays); 
    
    // Récupération de la capitale du pays en question 
    capitale = getCapitale(objetJson, indexPays); 
    
    // Récupération du nom du pays 
    nomPays = getNomPays(objetJson, indexPays); 
    
    // Affichage des langues
    char strLangues[MAXLENGTH] ; 
    getLangues(objetJson, indexPays, strLangues); 
    printf("%s", strLangues) ; 
    
    printf(" Abréviation 3 lettres : %s \n", countries_args->COUNTRY);
    printf(" Index : %d \n" , indexPays); 
    printf(" Capitale : %s \n", capitale); 
    printf(" Nom Pays : %s \n", nomPays); 
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
                strcpy(p->COUNTRY, optarg);
                break;
            case 'i':
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



