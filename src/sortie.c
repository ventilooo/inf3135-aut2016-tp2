#include "sortie.h"

FILE * initGraphFile(){

    FILE *fGraph;
    fGraph = fopen("dot.dot", "w+");
    fprintf(fGraph, "graph { \n");
    return fGraph;
}
void closeGraphFile(FILE *fGraph){

    fprintf(fGraph, "}\n");
    fclose(fGraph);
}
void addPays(json_t *objetJson, FILE *fGraph, int indexPays, bool capital, bool languages, bool borders){
    
    char *codeCible = getCode(objetJson, indexPays) ; 
    int i = 0 ; 
    
    fprintf(fGraph, "    %s [\n", codeCible);
    fprintf(fGraph, "        shape = none,\n");
    fprintf(fGraph, "        label = <<table border=\"0\" cellspacing=\"0\">\n");
    fprintf(fGraph, "            <tr><td align=\"center\" border=\"1\" fixedsize=\"true\" width=\"200\" height=\"100\"><img src=\"%s.png\" scale=\"true\"/></td></tr>\n", codeCible);
    fprintf(fGraph, "            <tr><td align=\"left\" border=\"1\"><b>Name</b>: %s</td></tr>\n", getNomPays(objetJson, indexPays));
    
    while(codeCible[i]) {
            codeCible[i] = toupper(codeCible[i]);
            i++;
     }
    
    fprintf(fGraph, "            <tr><td align=\"left\" border=\"1\"><b>Code</b>: %s</td></tr>\n", codeCible);
    capitalOut(objetJson, fGraph, indexPays, capital);
    languagesOut(objetJson, fGraph, indexPays, languages);
    bordersOut(objetJson, fGraph, indexPays, borders);
    fprintf(fGraph, "        </table>>\n");
    fprintf(fGraph, "    ];\n");

}

void languagesOut(struct json_t *objetJson, FILE *fGraph, int indexPays, bool languages){

    if(languages){
        char strLangues[MAXLENGTHLANGUES] = "" ;
        getLangues(objetJson, indexPays, strLangues);
        fprintf(fGraph, "            <tr><td align=\"left\" border=\"1\"><b>Language</b>: %s</td></tr>\n", strLangues);
    }
}

void capitalOut(struct json_t *objetJson, FILE *fGraph, int indexPays, bool capital){
    if(capital){
        fprintf(fGraph, "            <tr><td align=\"left\" border=\"1\"><b>Capital</b>: %s</td></tr>\n", getCapitale(objetJson, indexPays));
    }
}

void bordersOut(struct json_t *objetJson, FILE *fGraph, int indexPays, bool borders){
    if(borders){
        char strBorders[MAXLENGTHBORDERS] = "" ;
        getBorders(objetJson, indexPays, strBorders);
        fprintf(fGraph, "            <tr><td align=\"left\" border=\"1\"><b>Borders</b>: %s</td></tr>\n", strBorders);
    }
}

void regionOut(struct json_t *objetJson, int nombreTotalPays, char * filename, struct Countries_args *countries){

    int j ;
    FILE *fGraph;
    fGraph = initGraphFile();

    // Tableau des fichiers de la meme region 
    struct region_info *r = getPaysMemeRegion(objetJson ,nombreTotalPays, countries->REGION) ;
    for ( j = 0 ; j < r->nombrePays ; j++ ) {
        int indexCible = r->listeIndexPays[j] ; 
        addPays(objetJson, fGraph, indexCible, countries->SHOWCAPITAL, countries->SHOWLANGUAGES, countries->SHOWBORDERS);       
    }
   closeGraphFile(fGraph);
}

void paysOut(struct json_t *objetJson, char * filename,int indexPays,struct Countries_args *countries){
    FILE *fGraph;
    fGraph = initGraphFile();

    addPays(objetJson, fGraph, indexPays, countries->SHOWCAPITAL, countries->SHOWLANGUAGES, countries->SHOWBORDERS);


    closeGraphFile(fGraph);
}
/*
   void putBorder (frontieres, countryCode1, countryCode2){
   if(json_object_get(frontieres, 

   }*/
void affichageDot(){

    int c;
    FILE *fDot;
    fDot = fopen("dot.dot", "r");
printf("afficahge dot\n");
    if(fDot){
    printf("if FDot\n");
        while ((c = getc(fDot)) != EOF){
            putchar(c);
        }
        fclose(fDot);
        remove("dot.dot") ;
        exit(0);
    }else{
        printf("I/0 Exception\n");
        exit(1);
    }
}

void enregistrerDot(char * filename){

	if(filename == NULL){
		affichageDot() ;
	} else {
		rename("dot.dot", filename);
	}
}
