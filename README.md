# Travail pratique 2 

|DEVELOP|MASTER|
|:-------:|:-------:|
|[![build status](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/badges/develop/build.svg)](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/commits/develop)|[![build status](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/badges/master/build.svg)](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/commits/master)|

## Description

Il s'agit d'un programme qui lis une base donne en Json qui contient des information sur des pays.

En fonction des optionx choisie il genere different format de reponse:
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

### 1.
* **input:** : `bin/tp2 --country can`
* **output** : `Name: Canada
            Code: CAN`

### 2.
* **input:** : `bin/tp2 --region oceania --show-languages --show-capital --show-borders
Name: American Samoa`
* **output** : `Code: ASM
Capital: Pago Pago
Languages: English, Samoan
Borders:
Name: Australia
Code: AUS
Capital: Canberra
Languages: English
Borders:
...
Name: Samoa
Code: WSM
Capital: Apia
Languages: English, Samoan
Borders:
`

### 3.
* **input:** : `bin/tp2 --country can --show-languages --show-capital --show-borders \
> --show-flag --output-format dot`
* **output** : `graph {
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

* `bin/` -> executable(s)
* `data/` -> base de donnes
    * `countries/`
        * `CONTRIBUTING.md`
        * `LICENSE`
        * `...`
        * `package.json`
        * `src/`
* `src/` -> fichier source C
    * `tp2.c` -> logique generale du projet
    * `tp2.h` -> header du fichier `tp2.c`
    * `country.c` -> logique d'extraction des donner json pour les manipuler
    * `country.h` -> header du fichier `country.c` 
    * `sortie.c` -> logique de generation des foramat `.dot` et `.png`
    * `sortie.h` -> header du fichier `sortie.c` 
* `test/` -> fichier source `CUNIT` et `.bat`
* `Makefile` -> makefile du projet
* `README.md` -> presentation et documetation du projet
* `LICENCE` -> licence du projet
* `.gitignore` -> liste des fichier non versionner
* `.gitsubmodule` -> information sur les submodule
* `.gitab-ci.yml` -> configuration Gitlab-ci pour l'integration continue

## Références

* http://www.lacim.uqam.ca/~blondin/fr/inf3135-tp2

## [Taches](https://gitlab.com/ventilooo/inf3135-aut2016-tp2/boards)

## Statut

Work In Progress
