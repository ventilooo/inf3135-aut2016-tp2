# Travail pratique 2 

|DEVELOP|MASTER|
|:-------:|:-------:|
|[![build status](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/badges/develop/build.svg)](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/commits/develop)|[![build status](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/badges/master/build.svg)](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/commits/master)|

## Description

Il s'agit d'un programme qui lis une base donne en Json qui contient des information sur des pays.

En fonction des option choisie il genere different format de reponse:
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

Donnez la liste des bibliothèques et des logiciels qui doivent être installées
pour que le projet soit fonctionnel. Donnez le lien vers ceux-ci pour que
l'utilisateur puisse être redirigé vers les sites officiels des
logiciels/bibliothèques pour effectuer l'installation le cas échéant. N'oubliez
pas d'indiquer

## Installation

1. `make data`
2. `make`

## Fonctionnement

Expliquez brièvement comment utiliser votre programme avec au moins trois
exemples d'utilisation (commande lancée et résultat affiché).  Assurez-vous que
les exemples de commande lancée et de résultats obtenus sont formatés
correctement à l'aide de Markdown.

## Contenu du projet

* bin/ -> executable(s).
* data/ -> base de donnes.
    * countries/
        * CONTRIBUTING.md
        * LICENSE
        * ...
        * package.json
        * src/
* src/ -> fichier source C.
    * tp2.c -> logique generale du projet.
    * tp2.h -> header du fichier tp2.c .
    * country.c -> logique d'extraction des donner json pour les manipuler.
    * country.h -> header du fichier country.c .
    * sortie.c -> logique de generation des foramat `.dot` et `.png`. .
    * sortie.h -> header du fichier sortie.c .
* test/ -> fichier source `CUNIT` et `.bat`.
* Makefile -> makefile du projet.
* README.md -> presentation et documenation du projet.
* LICENCE -> licence du projet
* .gitignore -> liste des fichier non versionner
* .gitsubmodule -> information sur les submodule
* .gitab-ci.yml -> configuration Gitlab-ci pour l'integration continue.

## Références

Citez vos sources ici, s'il y a lieu.

## [Taches](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/boards)

## Statut

Work In Progress
