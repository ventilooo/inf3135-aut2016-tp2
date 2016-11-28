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
 * Structure associée aux arguments liés au pays.
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
 *  Structure asociée à la région
*/ 
struct region_info {
    int *listeIndexPays;
    int nombrePays ;
};

#endif /* COUNTRY_H */

/*
 * Retourne l'index du pays choisi. 
 *
 * @param *objetJson (contenu de la base de données json)
 * @param *pays (nom du pays passé)
 * @param nombreTotalPays (nombre total de pays contenu dans country.json) 
*/ 
int getIndexPays(json_t *objetJson, char* pays, int nombreTotalPays);

/*
 * Retourne la chaine de caractère correspondant à la capitale d'un pays.
 * 
 * @param *objetJson (contenu de la base de données json)
 * @param indexPays (index du pays)
*/ 
char* getCapitale(json_t *objetJson, int indexPays);

/*
 * Retourne la chaine de caractère correspondant au nom officiel d'un pays.
 * 
 * @param *objetJson (contenu de la base de données json)
 * @param indexPays (index du pays)
*/ 
char* getNomPays(json_t *objetJson, int indexPays);

/*
 * Retourne les langues correspondant à un pays.
 * 
 * @param *objetJson (contenu de la base de données json)
 * @param indexPays (index du pays)
 * @param *strLangues (liste des langues officielles du pays)
*/ 
void getLangues(json_t *objetJson, int indexPays, char* strLangues);

/*
 * Retourne la chaine de caractère correspondant aux pays frontaliers d'un pays.
 * 
 * @param *objetJson (contenue de la base de donne json)
 * @param indexPays (index d'un pays)
 * @param *strBorders (liste des pays frontalier)
*/ 
void getBorders(json_t *objetJson,int indexPays, char* strBorders);

/*
 * Récupère les pays de la région passée en paramètre
 * 
 * @param *objetJson (contenu de la base de donnée json)
 * @param nombreTotalPays (nombre total de pays contenu dans country.json) 
 * @param *REGION (region [exemple: amerique, asie, europe ...])
*/ 
struct region_info *getPaysMemeRegion(json_t *objetJson, int nombreTotalPays, char* REGION) ; 

/*
 * Affiche les information d'un pays en fonction des options.
 * 
 * @param *countrie_args (structure contenant les options passées en argument)
 * @param *objetJson (contenu de la base de donnée json)
 * @param nombreTotalPays (nombre total de pays contenus dans country.json) 
*/ 
void affichage(struct Countries_args *countries, json_t *objetJson ,int nombreTotalPays);

/*
 * Retourne la chaine de caractères correspondant à l'index d'un pays . 
 * 
 * @param *objetJson (contenu de la base de données json)
 * @param indexPays (index du pays)
*/ 
char* getCode(json_t *objetJson,int indexPays);

