"""
Module implémentant l'algorithme de Gale-Shapley pour l'affectation des étudiants aux parcours.

Fonctions principales:
- lire_pref_etudiants: Lecture des préférences des étudiants
- lire_pref_parcours: Lecture des préférences des parcours
- lire_capac_parcours: Lecture des capacités des parcours
- gale_shapley_etudiants: Algorithme côté étudiants
- gale_shapley_parcours: Algorithme côté parcours
- trouver_paires_instables: Validation des résultats

Format des fichiers d'entrée:
- PrefEtu.txt: n\n id_etudiant nom_etudiant pref1 pref2 ... pref9
- PrefSpe.txt: m\n capacites\n id_parcours nom_parcours pref1 pref2 ... prefn
"""

# Fonctions de lecture de fichiers
def lire_pref_etudiants(s):
    """
    Lit les préférences des étudiants depuis un fichier.
    
    Args:
        s (str): Chemin du fichier PrefEtu.txt
    Returns:
        list: Matrice CE des préférences où CE[i] = préférences de l'étudiant i
    """
    try:
        # Lecture des lignes du fichier
        monFichier = open(s, "r")
        contenu = monFichier.readlines()  
        monFichier.close()
    except FileNotFoundError:
        print(f"Erreur : le fichier {s} est introuvable.")
        return []

    CE = []  # Initialisation de la matrice des préférences des étudiants

    # Parcours des lignes contenant les préférences des étudiants
    for ligne in contenu[1:]:
        ligne = ligne.split()  # Découpe la ligne en éléments
        preferences = [int(x) for x in ligne[2:]]  # Convertit les préférences en entiers
        CE.append(preferences)  # Ajoute la ligne de préférences à la matrice

    return CE

def lire_pref_parcours(s):
    """
    Lit les préférences des parcours depuis un fichier.
    
    Args:
        s (str): Chemin du fichier PrefSpe.txt
    Returns:
        list: Matrice CP des préférences où CP[j] = préférences du parcours j
    """
    try:
        # Lecture des lignes du fichier
        monFichier = open(s, "r")
        contenu = monFichier.readlines()  
        monFichier.close()
    except FileNotFoundError:
        print(f"Erreur : le fichier {s} est introuvable.")
        return []

    CP = []  # Initialisation de la matrice des préférences des parcours

    # Parcours des lignes contenant les préférences des parcours
    for ligne in contenu[2:]:
        ligne = ligne.split()
        preferences = [int(x) for x in ligne[2:]]  # Convertit les préférences en entiers
        CP.append(preferences)

    return CP

def lire_capac_parcours(s):
    """
    Lit les capacités d'accueil des parcours.
    
    Args:
        s (str): Chemin du fichier PrefSpe.txt
    Returns:
        list: Liste des capacités de chaque parcours
    """
    try:
        # Lecture des lignes du fichier
        monFichier = open(s, "r")
        contenu = monFichier.readlines()  
        monFichier.close()
    except FileNotFoundError:
        print(f"Erreur : le fichier {s} est introuvable.")
        return []

    # Transformation de la deuxième ligne en liste d'entiers (capacités des parcours)
    return [int(x) for x in contenu[1].strip().split()[1:]]

def gale_shapley_etudiants(pref_etudiants, pref_parcours, capacites):
    """
    Algorithme de Gale-Shapley avec propositions des étudiants.
    
    Args:
        pref_etudiants (list): Matrice des préférences des étudiants
        pref_parcours (list): Matrice des préférences des parcours
        capacites (list): Capacités d'accueil des parcours
    
    Returns:
        dict: Affectation {parcours: [étudiants]}
    
    Complexité:
        - Temps: O(n*m) où n est le nombre d'étudiants et m le nombre de parcours
        - Espace: O(n+m) pour stocker les affectations et les rangs
    
    Garanties:
        - Termine toujours
        - Produit une affectation stable
        - Optimale du point de vue des étudiants
        - Respecte les capacités des parcours
    """
    # Étape 1 : Initialisation
    n_etudiants = len(pref_etudiants)
    n_parcours = len(pref_parcours)
    
    etudiants_libres = set(range(n_etudiants))  # Ensemble des étudiants libres
    propositions = {i: 0 for i in range(n_etudiants)}  # Dictionnaire indiquant le prochain parcours à qui proposer pour chaque étudiant
    affectation_parcours = {j: [] for j in range(n_parcours)}  # Dictionnaire des affectations des parcours
    ranks = {j: {etudiant: rank for rank, etudiant in enumerate(pref_parcours[j])} for j in range(n_parcours)}  # Rangs des étudiants pour chaque parcours
    
    # Étape 2 : Boucle principale
    while etudiants_libres:
        etudiant = etudiants_libres.pop()  # Prendre un étudiant libre
        parcours = pref_etudiants[etudiant][propositions[etudiant]]  # Le prochain parcours auquel il propose
        propositions[etudiant] += 1  # Passer au parcours suivant pour la prochaine fois
        
        # Ajouter l'étudiant au parcours
        affectation_parcours[parcours].append(etudiant)
        
        # Si le parcours dépasse sa capacité, éjecter le moins préféré
        if len(affectation_parcours[parcours]) > capacites[parcours]:
            # Trouver l'étudiant le moins préféré
            moins_prefere = max(affectation_parcours[parcours], key=lambda e: ranks[parcours][e])
            affectation_parcours[parcours].remove(moins_prefere)  # Retirer l'étudiant
            etudiants_libres.add(moins_prefere)  # Le moins préféré redevient libre
    
    return affectation_parcours

def gale_shapley_parcours(pref_etudiants, pref_parcours, capacites):
    """
    Algorithme de Gale-Shapley avec propositions des parcours.
    
    Args:
        pref_etudiants (list): Matrice des préférences des étudiants
        pref_parcours (list): Matrice des préférences des parcours
        capacites (list): Capacités d'accueil des parcours
    
    Returns:
        dict: Affectation {parcours: [étudiants]}
    
    Complexité:
        - Temps: O(n*m) où n est le nombre d'étudiants et m le nombre de parcours
        - Espace: O(n+m) pour stocker les affectations et les rangs
    
    Garanties:
        - Termine toujours
        - Produit une affectation stable
        - Optimale du point de vue des parcours
        - Respecte les capacités des parcours
    """
    n_etudiants = len(pref_etudiants)
    n_parcours = len(pref_parcours)

    # Étape 1 : Initialisation
    parcours_libres = set(range(n_parcours))  # Ensemble des parcours avec des places libres
    propositions = {i: 0 for i in range(n_parcours)}  # Dictionnaire indiquant le prochain etudiant à qui proposer pour chaque parcours
    affectation_parcours = {j: [] for j in range(n_parcours)}  # Affectations actuelles des parcours
    affectation_etudiants = {i: [] for i in range(n_etudiants)}  # Affectations actuelles des etudiants
    ranks = {i: {parcours: rank for rank, parcours in enumerate(pref_etudiants[i])} for i in range(n_etudiants)} # Rangs des parcours pour chaque etudiant

    # Étape 2 : Boucle principale
    while parcours_libres:
        # Prendre un parcours avec des places libres
        parcours = parcours_libres.pop()
        
        while len(affectation_parcours[parcours]) < capacites[parcours]:
            # Prochaine proposition du parcours
            etudiant = pref_parcours[parcours][propositions[parcours]]
            propositions[parcours] += 1  # Passer au prochain etudiant pour la prochaine fois
            # Ajouter l'étudiant au parcours
            affectation_etudiants[etudiant].append(parcours)
            affectation_parcours[parcours].append(etudiant)
            
            # Si l'etudiant est dans deux parcours à la fois, éjecter le moins préféré
            if len(affectation_etudiants[etudiant]) > 1:
                # Trouver le parcours le moins préféré
                moins_prefere = max(affectation_etudiants[etudiant], key=lambda e: ranks[etudiant][e])
                affectation_etudiants[etudiant].remove(moins_prefere)  # Retirer le parcours
                affectation_parcours[moins_prefere].remove(etudiant) # Retirer l'etudiant 

                # si le parcours moins préféré n'est pas le parcours courant
                if moins_prefere != parcours:
                    parcours_libres.add(moins_prefere)  # Remettre le parcours éjecté dans les libres

    return affectation_parcours

def trouver_paires_instables(affectation, pref_etudiants, pref_parcours):
    """
    Identifie les paires instables dans une affectation.
    
    Args:
        affectation (dict): Affectation à vérifier
        pref_etudiants (list): Matrice des préférences des étudiants
        pref_parcours (list): Matrice des préférences des parcours
    
    Returns:
        list: Liste des paires instables [(parcours, étudiant)]
    
    Une paire (e,p) est instable si:
        1. e préfère p à son affectation actuelle
        2. p préfère e à au moins un de ses étudiants actuels
    
    Complexité:
        - Temps: O(n^2) où n est le nombre d'étudiants
        - Espace: O(n) pour stocker les rangs et les paires instables
    """
    n_etudiants = len(pref_etudiants)
    n_parcours = len(pref_parcours)
    ranks_parcours = {i: {parcours: rank for rank, parcours in enumerate(pref_etudiants[i])} for i in range(n_etudiants)}
    ranks_etudiants = {j: {etudiant: rank for rank, etudiant in enumerate(pref_parcours[j])} for j in range(n_parcours)}
    paires_instables = set()  # Utiliser un set pour éviter les doublons

    # Trouver le parcours actuel de chaque étudiant
    parcours_de_etudiant = {}
    for p, etudiants in affectation.items():
        for e in etudiants:
            parcours_de_etudiant[e] = p

    # Pour chaque étudiant
    for etudiant in range(n_etudiants):
        parcours_actuel = parcours_de_etudiant.get(etudiant)
        if parcours_actuel is None:
            continue

        # Parcours préférés par cet étudiant par rapport à son affectation actuelle
        for parcours in pref_etudiants[etudiant]:
            # Si l'étudiant préfère ce parcours à son affectation actuelle
            if ranks_parcours[etudiant][parcours] < ranks_parcours[etudiant][parcours_actuel]:
                # Si le parcours n'a pas atteint sa capacité ou préfère cet étudiant à un de ses étudiants actuels
                if parcours in affectation:
                    moins_prefere = max(affectation[parcours], key=lambda e: ranks_etudiants[parcours][e])
                    # Vérifier d'abord si la paire serait instable
                    if ranks_etudiants[parcours][etudiant] < ranks_etudiants[parcours][moins_prefere]:
                        paires_instables.add( (parcours, etudiant) )

    return list(paires_instables)

