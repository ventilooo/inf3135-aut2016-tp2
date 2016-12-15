Correction du TP2
~~~~~~~~~~~~~~~~~

Étudiants
=========

- Pascal Vautour (VAUP05049304)
- Nizar Semlali (SEMN14019103)
- Istvan Szalai (SZAI29079604)

Résultat
========

+-------------------------+-----------------------------+-----------+-----------+
| Critère                 | Description                 | Note      | Sur       |
+=========================+=============================+===========+===========+
|                         | Affichage des informations, |           |           |
|                         | traitement des arguments,   |           |           |
| Fonctionnabilité        | lecture du format JSON,     | 59        | 60        |
|                         | écriture au format dot,     |           |           |
|                         | appel de Graphviz, etc.     |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Style et documentation,     |           |           |
| Qualité du code         | décomposition modulaire,    | 29        | 30        |
|                         | encapsulation, etc.         |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Respect du format Markdown, |           |           |
| Fichier README          | qualité du contenu, tâches  | 30        | 30        |
|                         |                             |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Compilation, nettoyage,     |           |           |
| Makefile                | mise à jour de la base de   |           |           |
|                         | données                     | 20        | 20        |
|                         | (``make``, ``make clean``,  |           |           |
|                         | ``make data``)              |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Qualité de la couverture,   |           |           |
| Tests                   | utilisabilité, lisibilité,  | 28        | 30        |
|                         | fonctionnabilité            |           |           |
|                         | (``make test``)             |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | *Commits* liés à une tâche  |           |           |
| Utilisation de Git      | spécifique, message clair   | 30        | 30        |
|                         | et pertinent, gestion d'un  |           |           |
|                         | sous-module, collaboration, |           |           |
|                         | etc.                        |           |           |
+-------------------------+-----------------------------+-----------+-----------+
| **Total**                                             | **196**   | **200**   |
+-------------------------+-----------------------------+-----------+-----------+

Commentaires
============

- La compilation génère quelques avertissements. J'ai dû aussi modifier un peu
  le Makefile pour que CUnit soit retrouvé.
- Toutes les fonctionnalités semblent correctes sur Malt. Il y a des liens
  multiples entre les pays sur la carte (juste un lien aurait été préférable).
- La qualité du code est bonne en général. Les docstrings sont soignées et le
  programme est modulaire.
- Attention aux valeurs magiques (y compris les chaînes de caractères).
- README impeccable.
- Makefile impeccable et fonctionnel.
- Bonne configuration de tests automatiques. La couverture aurait pu être un
  peu plus exhaustive.
- Bravo pour l'utilisation de branches sous Git.
- Bonne collaboration entre les membres de l'équipe.
