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

#include "link.h"
#define MAXLENGTHLANGUES 400
#define MAXLENGTHBORDERS 75
#ifndef COUNTRY_H
#define COUNTRY_H

/*
 * Structure associer aux arguments lie au pays.
*/ 
struct Countries_args {
    char *FILENAME;
    char FORMAT[5];
    bool SHOWLANGUAGES;
    bool SHOWCAPITAL;
    bool SHOWBORDERS;
    bool SHOWFLAG;
    bool SHOWCOUNTRY;
    bool SHOWREGION ; 
    char COUNTRY[4];
    char REGION[8];
};

/*
 *  Structure asocier au region
*/ 
struct region_info {
    int *listeIndexPays;
    int nombrePays ;
};

#endif /* COUNTRY_H */

/*
 * Retourne l'index du pays choisie. 
 *
 * @param *objetJson (contenue de la base de donne json)
 * @param *pays (nom du pays passer)
 * @param nombreTotalPays (nombre total de pays contenue dans country.json) 
*/ 
int getIndexPays(json_t *objetJson, char* pays, int nombreTotalPays);

/*
 * Retourne la chaine de caractere correspondant a la capital d'un pays.
 * 
 * @param *objetJson (contenue de la base de donne json)
 * @param indexPays (index d'un pays)
*/ 
const char* getCapitale(json_t *objetJson, int indexPays);

/*
 * Reddtourne la chaine de caractere correspondant au nom officiel d'un d'un pays.
 * 
 * @param *objetJson (contenue de la base de donne json)
 * @param indexPays (index d'un pays)
*/ 
const char* getNomPays(json_t *objetJson, int indexPays);

/*
 * Reddtourne la chaine de caractere correspondant au nom officiel d'un d'un pays.
 * 
 * @param *objetJson (contenue de la base de donne json)
 * @param indexPays (index d'un pays)
 * @param *strLangues (liste des langues officiel d'un pays)
*/ 
void getLangues(json_t *objetJson, int indexPays, char* strLangues);

/*
 * Reddtourne la chaine de caractere correspondant au nom officiel d'un d'un pays.
 * 
 * @param *objetJson (contenue de la base de donne json)
 * @param indexPays (index d'un pays)
 * @param *strBorders (liste des pays frontalier)
*/ 
void getBorders(json_t *objetJson,int indexPays, char* strBorders);

/*
 * Retourne la chaine de caractere correspondant au nom officiel d'un d'un pays.
 * 
 * @param *objetJson (contenue de la base de donne json)
 * @param nombreTotalPays (nombre total de pays contenue dans country.json) 
 * @param *REGION (region [exemple: amerique, asie, europe ...])
*/ 
struct region_info *getPaysMemeRegion(json_t *objetJson, int nombreTotalPays, char* REGION) ; 

/*
 * Affiche les information d'un d'un pays en fonction des options.
 * 
 * @param *countrie_args (structure contenant les options passer en arguments)
 * @param *objetJson (contenue de la base de donne json)
 * @param nombreTotalPays (nombre total de pays contenue dans country.json) 
*/ 
void affichage(struct Countries_args *countries, json_t *objetJson ,int nombreTotalPays);

/*
 * Retourne la chaine de caractere correspondant au code d'un d'un pays.
 * 
 * @param *objetJson (contenue de la base de donne json)
 * @param indexPays (index d'un pays)
*/ 
char* getCode(json_t *objetJson,int indexPays);

