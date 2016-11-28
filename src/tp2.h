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

/*
 * Lis les arguments passés au programme et initialise les paramètres 
 * qui serviront à l'execution du programme.
 *
 * @param argc
 * @param argv
 */
struct Countries_args *getOpts(int argc, char *argv[]);

/*
 * Imprime à l'écran le message d'aide et termine le programme.
*/
void usage();
