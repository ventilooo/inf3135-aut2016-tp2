# Travail pratique 2 

|DEVELOP|MASTER|
|:-------:|:-------:|
|[![build status](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/badges/develop/build.svg)](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/commits/develop)|[![build status](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/badges/master/build.svg)](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/commits/master)|

## Description

Il s'agit d'un programme qui lit une base de données en Json qui contient des information sur des pays.
L'utilisateur peut choisir quelles informations afficher, à savoir la capitale, les langues parlées, les frontières du pays ...


En fonction des option choisies il génère différents formats de sortie:
* text
* .png
* .dot

(Construction et maintenance de logiciels, INF3135, UQAM, Automne 2016)

## Auteurs

- Pascal Vautour (VAUP05049304)
- Nizar Semlali (SEMN14019103)
- Istvan Szalai (SZAI29079604)

## Plateformes supportées

* Ubuntu 16.04
* Linux Mint 18
* mac OS Sierra 10.12.1

## Dépendances

* [libjansson](https://jansson.readthedocs.io/en/2.9/)
* [CUNIT](http://cunit.sourceforge.net/doc/index.html)
* [bats](https://github.com/sstephenson/bats)

## Installation

1. `make data`
2. `make`

## Fonctionnement

Exemples d'utilisation : ( Étant donné que les régions affichent plusieurs résultats, nous nous contentons de donner des exemples pour les pays ) : 

### 1. Le cas d'utilisation le plus simple permet d'afficher à la console le nom d'un pays dont on donne le code :
* **input:** `./tp2 --country can`
* **output:** `Name: Canada 
	Code: CAN`
		 
### 2. On peut afficher certaines options, comme la capitale, les langues parlées, les frontières :

* **input:** `./tp2 --country can --show-borders --show-capital --show-languages`
* **output:**	`Name: Canada 
	Code: CAN
	Capital: Ottawa 
	Languages: English, French 
	Borders: USA`
	
  
		 
### 3. On peut afficher l'information relative à un fichier ou une région au format dot :
* **input:** `bin/tp2 --country can --show-languages --show-capital --show-borders \
> --show-flag --output-format dot`
* **output:** `graph {
    can [
        shape = none,
        label = <<table border="0" cellspacing="0">
            <tr><td align="center" border="1" fixedsize="true" width="200" height="100"><img src="can.png" scale="true"/></td></tr>
            <tr><td align="left" border="1"><b>Name</b>: Canada</td></tr>
            <tr><td align="left" border="1"><b>Code</b>: CAN</td></tr>
            <tr><td align="left" border="1"><b>Capital</b>: Ottawa</td></tr>
            <tr><td align="left" border="1"><b>Language</b>: French, English</td></tr>
            <tr><td align="left" border="1"><b>Borders</b>: USA</td></tr>
        </table>>
    ];
}`

## Contenu du projet

* `bin/` -> Executable(s)
* `data/` -> Base de données
    * `countries/`
        * `CONTRIBUTING.md`
        * `LICENSE`
        * `...`
        * `package.json`
        * `src/`
* `src/` -> Fichier source C
    * `tp2.c` -> Logique générale du projet ( Avec le main ) 
    * `tp2.h` -> Header du fichier `tp2.c`
    * `country.c` -> Logique d'extraction des données Json pour les manipuler
    * `country.h` -> Header du fichier `country.c` 
    * `sortie.c` -> Logique de génération des formats `.dot` et `.png`
    * `sortie.h` -> Header du fichier `sortie.c` 
* `test/` -> Fichier source `CUNIT` et `.bat`
* `Makefile` -> Makefile du projet
* `README.md` -> Présentation et documentation du projet
* `LICENCE` -> License du projet
* `.gitignore` -> Liste des fichiers non versionnés
* `.gitsubmodule` -> Informations sur les submodules
* `.gitab-ci.yml` -> Configuration Gitlab-ci pour l'intégration continue

## Références

* http://www.lacim.uqam.ca/~blondin/fr/inf3135-tp2

## [Taches](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/boards)

## Statut

Complété , sauf que les frontières entre les pays sont affichées en double . 
