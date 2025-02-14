# Affectation des Étudiants aux Parcours

Ce projet implémente plusieurs algorithmes pour résoudre le problème d'affectation des étudiants aux parcours universitaires.

## Description

Le programme permet de :
- Implémenter l'algorithme de Gale-Shapley (versions étudiants et parcours)
- Générer et résoudre des modèles de programmation linéaire
- Analyser la stabilité des affectations
- Mesurer les performances des algorithmes

## Structure du Projet

- `ex1.py` : Implémentation de l'algorithme de Gale-Shapley
- `ex2.py` : Génération de données et mesures de performance
- `ex3.py` : Génération de fichiers de programmation linéaire
- `main.py` : Interface utilisateur et programme principal

## Format des Fichiers d'Entrée

### PrefEtu.txt
```
n
id_etudiant nom_etudiant pref1 pref2 ... pref9
...
```

### PrefSpe.txt
```
m
capacite1 capacite2 ... capacite9
id_parcours nom_parcours pref1 pref2 ... prefn
...
```

## Utilisation

1. Lancer le programme :
```bash
python main.py
```

2. Menu des options :
   - 1 : Exécuter toutes les options
   - 2 : Afficher les données
   - 3 : Gale-Shapley côté étudiants
   - 4 : Gale-Shapley côté parcours
   - 5 : Analyse de stabilité
   - 6 : Test de performance
   - 7-9 : Génération de fichiers PLNE
   - 10 : Analyse des solutions PLNE

## Solutions PLNE

Les fichiers générés sont au format LP standard :
- `pl_k_premiers.lp` : PLNE pour les k premiers choix
- `pl_utilites.lp` : PLNE maximisant l'utilité totale
- `pl_utilites_k.lp` : PLNE combinant les deux approches

## Analyse des Résultats

Le programme permet de :
- Visualiser les affectations
- Détecter les paires instables
- Comparer les temps d'exécution
- Analyser les solutions PLNE

## Licence

Ce projet est sous licence MIT.
