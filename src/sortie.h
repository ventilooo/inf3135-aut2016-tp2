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

#include "country.h"

/*
 * Creation du fichier vide ".dot".
*/
FILE * initGraphFile();

/*
 * Ferme le canal du fichier ".dot".
 *
 * @param *fGraph (fichier "dot.dot")
*/
void closeGraphFile(FILE *fGraph);

/*
 * Ajoute les informations d'un pays au format "dot" dans un fichier ".dot".
 *
 * @param *objetJson (Objet associé au contenu de countries.json)
 * @param *fGraph (Fichier "dot.dot")
 * @param indexPays (Index du pays)
 * @param capital (Capitale du pays)
 * @param languages (Langues officielles du pays)
 * @param borders (pays frontaliers du pays selectionné)
*/
void addPays(struct json_t *objetJson, FILE *fGraph, int indexPays, bool capital, bool languages, bool borders);

/*
 * Ajoute les langues officielles d'un pays dans un fichier au format dot.
 *
 * @param *objetJson (Objet associé au contenu de countries.json)
 * @param *fGraph (Fichier "dot.dot")
 * @param indexPays (Index d'un pays)
 * @param languages (Langues officielles d'un pays)
*/
void languagesOut(struct json_t *objetJson, FILE *fGraph, int indexPays, bool languages);

/*
 * Ajoute la capitale d'un pays dans un fichier au format dot.
 *
 * @param *objetJson (Objet associé au contenu de countries.json)
 * @param *fGraph (Fichier "dot.dot")
 * @param indexPays (Index du pays)
 * @param capital (Capital du pays)
*/
void capitalOut(struct json_t *objetJson, FILE *fGraph, int indexPays, bool capital);

/*
 * Ajoute les pays limitrophe d'un pays en option dans un fichier au format dot.
 *
 * @param *objetJson (Objet associé au contenu de countries.json)
 * @param *fGraph (Fichier "dot.dot")
 * @param indexPays (Index du pays)
 * @param borders (pays frontalier du pays sélectionné)
*/
void bordersOut(struct json_t *objetJson, FILE *fGraph, int indexPays, bool borders);

/*
 * Ajoute les pays associés à une region dans un fichier au format dot.
 *
 * @param *objetJson (Objet associé au contenu de counries.json)
 * @param nombreTotalPays (Nombre total de pays dans countries.json)
 * @param *filename (Nom du fichier)
 * @param *Countries_args (Liste des options)
*/
void regionOut(struct json_t *objetJson, int nombreTotalPays, char * filename, struct Countries_args *countries);

/*
 * Ajoute les frontières des pays dans un fichier au format dot.
 *
 * @param frontieres (Frontières d'un pays)
 * @param indexPays (Index du pays)
*/
void frontieresOut(struct json_t frontieres, int indexPays);

/*
 * Ajoute un pays dans un fichier au format dot.
 *
 * @param *objetJson (Objet associé au contenu de countries.json)
 * @param *filename (Nom du fichier)
 * @param indexPays (L'index du pays)
 * @param *Countries_args (Liste des options)
*/
void paysOut(struct json_t *objetJson, char * filename,int indexPays, struct Countries_args *countries);

/*
 * Affichage du fichier dot.
*/
void affichageDot();

/*
 * Vérifie le format et le filename, et dirige vers le traitement approprié . 
 *
 * @param *filename (Nom du fichier)
 * @param *FORMAT (Format du fichier)
*/
void enregistrerDot(char * filename, char* FORMAT) ; 

/*
 * Appel de graphviz pour créer les images png.
 *
 * @param *filename (Nom du fichier)
*/
void graphviz(char * filename);



/*
 * Ajoute les relations entre les pays au fichier principal.
 *
 * @param *fGraph (Fichier principal à afficher)
 *
 * @param *borders (Fichier contenant les relations entre les pays)
*/
void mergeBordersTofGraph(FILE *fGraph, FILE *borders);
