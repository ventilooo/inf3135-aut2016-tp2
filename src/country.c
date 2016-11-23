#include "country.h" 



int getIndexPays(json_t *objetJson, char* pays, int nombreTotalPays) {

	int indexPays = 0; 
	json_t *paysCible; 
	json_t *ciocPays; 
	char *ciocCorrespondant;
	int i; 
	
	
	for ( i = 0 ; i < nombreTotalPays ; i++ ) {
	
		paysCible = json_array_get(objetJson, i);
		ciocPays = json_object_get(paysCible,"cioc");
		ciocCorrespondant = json_string_value(ciocPays) ;
		if ( strcasecmp(pays, ciocCorrespondant) == 0 ) {
			indexPays = i;
		}	
	}
	return indexPays; 
}

char* getCapitale(json_t *objetJson, int indexPays) {
	
	 json_t *paysCible;
	 json_t *valeurCapitale; 
	
	 paysCible = json_array_get(objetJson, indexPays);
     valeurCapitale = json_object_get(paysCible, "capital");
     char *capitale = json_string_value(valeurCapitale);
     
     return capitale;
}

char* getNomPays(json_t *objetJson, int indexPays) {

	json_t *paysCible;
	json_t *nomsDuPays;
	json_t *nomCommun;
	
	paysCible = json_array_get(objetJson, indexPays);
	nomsDuPays = json_object_get(paysCible,"name");  
	nomCommun = json_object_get(nomsDuPays,"common");
	char *nomCommunPays = json_string_value(nomCommun);
    
    return nomCommunPays;
}

void getLangues(json_t *objetJson, int indexPays, char* strLangues) {

	json_t *paysCible; 
	json_t *languesDuPays; 
	const char *key;
    json_t *value;
    char *langue ;
	
	paysCible = json_array_get(objetJson, indexPays) ; 
	languesDuPays = json_object_get(paysCible,"languages");
	json_object_foreach(languesDuPays, key, value) {
		langue = json_string_value(value) ; 
		if(strlen(strLangues) == 0 ) {
			strcat(strLangues,langue);
		} else {
		strcat(strLangues,", "); 
		strcat(strLangues,langue);
		}
	}

}

void getBorders(json_t *objetJson,int indexPays, char* strBorders) {

	json_t *paysCible; 
	json_t *tableauBorders; 
	size_t index ; 
    json_t *value;
    char *border ;
    
    paysCible = json_array_get(objetJson, indexPays) ; 
	tableauBorders = json_object_get(paysCible,"borders");
	
	json_array_foreach(tableauBorders,index,value){
		border = json_string_value(value) ; 
		if(strlen(strBorders) == 0 ) {
			strcat(strBorders,border);
		} else {
			strcat(strBorders,", "); 
			strcat(strBorders,border);
		}
		
	}
}



struct region_info *getPaysMemeRegion(json_t *objetJson,int nombreTotalPays, char* REGION) {

	struct region_info *r = malloc(sizeof(struct region_info));
    
	json_t *paysCible; 
	json_t *regionPays; 
	char *regionCorrespondante;
	int i; 
	int size = 0 ; 
	//int* tab ;  

	for ( i = 0 ; i < nombreTotalPays ; i++ ) {
	
		paysCible = json_array_get(objetJson, i);
		regionPays = json_object_get(paysCible,"region");
		regionCorrespondante = json_string_value(regionPays) ;
		if ( strcasecmp(REGION, regionCorrespondante) == 0 ) {
			if ( size == 0 ) {
				r->listeIndexPays = malloc(sizeof(int)) ; 
				r->listeIndexPays[0] = i ; 
				size++; 
			} else {
				size++ ; 
				r->listeIndexPays = realloc(r->listeIndexPays,sizeof(int)*size);
				r->listeIndexPays[size-1] = i ; 
			}
		}	
	}
	
	r->nombrePays = size ; 
	return r ; 


}


void affichage(struct Countries_args *countries, json_t *objetJson ,int nombreTotalPays) { 

	int indexPays; 
	char *capitale; 
	char *nomPays;
	int i = 0 ;
	
	if ( countries->SHOWCOUNTRY ) {
	
		indexPays = getIndexPays(objetJson,countries->COUNTRY,nombreTotalPays);
		nomPays = getNomPays(objetJson, indexPays); 
		
		printf("Name: %s \n",nomPays) ; 
		printf("Code: ") ;
		while(countries->COUNTRY[i]) {
      		putchar(toupper(countries->COUNTRY[i]));
      		i++;
   		}
	    printf("\n") ;
		 
		if ( countries->SHOWCAPITAL) {
			capitale = getCapitale(objetJson, indexPays); 
			printf("Capital: %s \n",capitale) ; 
		}  
		if ( countries->SHOWLANGUAGES ) {
			char strLangues[MAXLENGTHLANGUES] ; 
			getLangues(objetJson, indexPays, strLangues); 
			printf("Languages: %s \n",strLangues) ; 
		}
		if ( countries->SHOWBORDERS ) {
			char strBorders[MAXLENGTHBORDERS];
    		getBorders(objetJson, indexPays, strBorders); 
			printf("Borders: %s \n",strBorders) ;
		}
	} else if ( countries->SHOWREGION ) {
		printf("Montrer la région \n") ; 
	}
	
}
	
	
	
