/****************************************************************************
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
* 	Copyright [2016] [Pascal Vautour]
* 	Copyright [2016] [Nizar Semlali]
* 	Copyright [2016] [Istvan Szalai]
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
****************************************************************************/

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
    fprintf(fGraph, "            <tr><td align=\"center\" border=\"1\" fixedsize=\"true\" width=\"200\" height=\"100\"><img src=\"../data/countries/data/%s.png\" scale=\"true\"/></td></tr>\n", codeCible);
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
    char * frontieres = malloc(1);
	//int[300] frontieres1;
	//int[300] frontieres2;

    // Tableau des fichiers de la meme region 
    struct region_info *r = getPaysMemeRegion(objetJson ,nombreTotalPays, countries->REGION) ;
    for ( j = 0 ; j < r->nombrePays ; j++ ) {
        int indexCible = r->listeIndexPays[j] ; 
        addPays(objetJson, fGraph, indexCible, countries->SHOWCAPITAL, countries->SHOWLANGUAGES, countries->SHOWBORDERS);
       // addBorderOut (&frontieres1, &frontieres2, int countryIndex1, int countryIndex2) ;
addFrontieresDotOut(&frontieres, objetJson,indexCible)
    }
    
    
   // bordersOut(fGraph, &frontieres1, &frontieres2, objetJson) ; 
   closeGraphFile(fGraph);
}



void paysOut(struct json_t *objetJson, char * filename,int indexPays,struct Countries_args *countries){
    FILE *fGraph;
    fGraph = initGraphFile();

    addPays(objetJson, fGraph, indexPays, countries->SHOWCAPITAL, countries->SHOWLANGUAGES, countries->SHOWBORDERS);


    closeGraphFile(fGraph);
}




	
	
	   
void affichageDot(){

    int c;
    FILE *fDot;
    fDot = fopen("dot.dot", "r");

    if(fDot){
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

void enregistrerDot(char * filename, char* FORMAT){

	if(filename == NULL){
		affichageDot() ;
	} else if(strcmp(FORMAT,"png") == 0){
		graphviz(filename);
	} else {
		rename("dot.dot", filename);
	}
}

void graphviz(char * filename){


	char chaine1[32] ; 
	char chaine2[9] ; 
	strcpy(chaine1,"neato -Goverlap=false -Tpng -o ");
	strcpy(chaine2," dot.dot");
	
	char *commandeSysteme = malloc(sizeof(chaine1) + sizeof(chaine2) + sizeof(filename)) ; 
	
	strcpy(commandeSysteme, chaine1);
	strcat(commandeSysteme,filename) ; 
	strcat(commandeSysteme,chaine2) ;

	system(commandeSysteme);
	remove("dot.dot") ;
	free(commandeSysteme);
	
}
/*
void addBorderListOut(char * countryList){

char s[80];
char *pc;
strcpy(s, countryList);
printf("Avec strstok:\n");
pc = strtok(s, DELIMS);
while (pc != NULL) {
    addBorderOut( pc);
    pc = strtok(NULL, DELIMS);
}


}

bool addBorderOut (int [] *frontieres1, int[] *frontieres2, char * country, char * countryList){
    
	int i = 0;
	
	while (frontieres1[i] != NULL){
	
		if(frontieres1[i] == countryIndex2 && frontieres2[i] == countryIndex1){
	
		return false;
		}
		i++;
	}
	
	frontieres1[i] = countryIndex1;
	frontieres2[i] = countryIndex2;
	
	return true;
	
}

	
	
	

void bordersOut(FILE *fGraph, int [] *frontieres1, int[] *frontieres2, json_t *objetJson){
	int i = 0;
	while(frontieres1[i] != NULL){
	
		fprintf(fGraph, "%s -- %s;\n", getCode(objetJson, frontieres1[i]), frontieres2[i]);
	
	}
	
	
}
*/
void addFrontieresDotOut(unsigned char **frontieres, json_t *objetJson,int indexPays){

   char * ajout;
  getBorders(objetJson,indexPays, ajout);

   realloc(frontieres, sizeof(frontieres) + sizeof(ajout));
    frontieres = strcat(frontieres, ajout);


}


