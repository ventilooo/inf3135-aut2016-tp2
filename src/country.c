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


void affichage(bool SHOWCAPITAL, bool SHOWLANGUAGES, bool SHOWFLAG, bool SHOWBORDERS, char country[], char region[]){ 
	
	if ( SHOWCAPITAL ) {
		
	}  
	
	if ( SHOWLANGUAGES ) {
		
	}
	
	if ( SHOWBORDERS ) {
	
	}
}
