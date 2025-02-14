"""
Module de génération de fichiers de programmation linéaire pour l'optimisation
de l'affectation des étudiants aux parcours.

Fonctions:
- genere_fichier_lp: Génère un fichier LP pour les k premiers choix des étudiants
- generer_fichier_plne_max_utilite: Génère un PLNE maximisant l'utilité totale
"""

def generer_fichier_plne_k_premiers(preferences_etudiants, capacites, k, nom_fichier="fichierpl.lp"):
    """
    Génère un fichier LP pour résoudre le problème d'affectation restreint 
    aux k premiers choix des étudiants.

    Args:
        preferences_etudiants (list): Matrice des préférences des étudiants
        capacites (list): Liste des capacités de chaque parcours
        k (int): Nombre de premiers choix à considérer
        nom_fichier (str): Nom du fichier LP à générer

    Le problème maximise le nombre d'étudiants affectés à un de leurs k premiers choix
    sous les contraintes:
    - Chaque étudiant est affecté à au plus un parcours
    - Les capacités des parcours sont respectées
    """
    n = len(preferences_etudiants)  # Nombre d'étudiants
    m = len(capacites)  # Nombre de parcours
    
    # Génération des paires (i, j) où j est dans les k premiers choix de i
    E = []
    for i, prefs in enumerate(preferences_etudiants):
        for j in prefs[:k]:  # On prend les k premiers choix
            E.append((i, j))
    
    with open(nom_fichier, "w") as f:
        # Écriture de la fonction objectif
        f.write("Maximize\n")
        f.write("    " + " + ".join([f"x{i}_{j}" for (i, j) in E]) + "\n\n")
        
        # Contraintes
        f.write("Subject To\n")
        
        # Chaque étudiant est affecté à au plus un parcours
        for i in range(n):
            terms = [f"x{i}_{j}" for j in preferences_etudiants[i][:k]]
            if terms:
                f.write(f"    {' + '.join(terms)} = 1\n")
        
        # Les capacités des parcours sont respectées
        for j in range(m):
            terms = [f"x{i}_{j}" for i in range(n) if (i, j) in E]
            if terms:
                f.write(f"    {' + '.join(terms)} <= {capacites[j]}\n")
        
        f.write("\nBinary\n")
        
        # Déclaration des variables binaires
        for (i, j) in E:
            f.write(f"    x{i}_{j}\n")
        
        f.write("End\n")
    
    print(f"\nFichier {nom_fichier} généré avec succès.")


def generer_fichier_plne_max_utilite(preferences_etudiants, preferences_parcours, capacites, nom_fichier):
    """
    Génère un fichier PLNE pour maximiser la somme des utilités des étudiants et parcours.

    Args:
        preferences_etudiants (list): Matrice des préférences des étudiants
        preferences_parcours (list): Matrice des préférences des parcours
        capacites (list): Liste des capacités de chaque parcours
        nom_fichier (str): Nom du fichier LP à générer

    L'utilité est calculée comme suit:
    - Pour un étudiant e et parcours p: utilité = m - rang(p dans préférences de e)
    - Pour un parcours p et étudiant e: utilité = n - rang(e dans préférences de p)

    Les contraintes assurent:
    - Chaque étudiant est affecté à exactement un parcours
    - Les capacités des parcours sont respectées
    - Toutes les variables d'affectation sont binaires
    """
    n = len(preferences_etudiants)
    m = len(preferences_parcours)
    
    # Calcul des utilités
    utilites_etudiants = [[m-1 - preferences_etudiants[e].index(p) for p in range(m)] for e in range(n)]
    utilites_parcours = [[n-1 - preferences_parcours[p].index(e) for e in range(n)] for p in range(m)]
    
    with open(nom_fichier, "w") as f:
        # Fonction objectif - maximiser la somme des utilités
        f.write("maximize\n")
        obj_etudiants = " + ".join([f"{utilites_etudiants[e][p]} x{e}_{p}" 
                                   for e in range(n) for p in range(m)])
        obj_parcours = " + ".join([f"{utilites_parcours[p][e]} x{e}_{p}" 
                                  for p in range(m) for e in range(n)])
        f.write(f"  obj: {obj_etudiants} + {obj_parcours}\n\n")
        
        f.write("subject to\n")
        
        # Chaque étudiant est affecté à exactement un parcours
        for e in range(n):
            constraint = " + ".join([f'x{e}_{p}' for p in range(m)])
            f.write(f"  c{e}: {constraint} = 1\n")
        
        # Respect des capacités des parcours
        for p in range(m):
            constraint = " + ".join([f'x{e}_{p}' for e in range(n)])
            f.write(f"  c{n+p}: {constraint} <= {capacites[p]}\n")
        
        # Les variables binaires
        f.write("\nBinary\n")
        for e in range(n):
            for p in range(m):
                f.write(f"  x{e}_{p}\n")
        
        f.write("end\n")

    print(f"\nFichier {nom_fichier} généré avec succès.")


def generer_fichier_plne_max_utilite_k_premiers(preferences_etudiants, preferences_parcours, capacites, k, nom_fichier):
    """
    Génère un fichier PLNE pour maximiser la somme des utilités en se limitant 
    aux k premiers choix de chaque étudiant.

    Args:
        preferences_etudiants (list): Matrice des préférences des étudiants
        preferences_parcours (list): Matrice des préférences des parcours
        capacites (list): Liste des capacités de chaque parcours
        k (int): Nombre de premiers choix à considérer
        nom_fichier (str): Nom du fichier LP à générer

    L'utilité est calculée comme suit:
    - Pour un étudiant e et parcours p: utilité = m - rang(p dans préférences de e)
    - Pour un parcours p et étudiant e: utilité = n - rang(e dans préférences de p)
    Avec la contrainte supplémentaire que chaque étudiant ne peut être affecté
    qu'à un de ses k premiers choix.
    """
    n = len(preferences_etudiants)
    m = len(preferences_parcours)
    
    # Calcul des utilités
    utilites_etudiants = [[m-1 - preferences_etudiants[e].index(p) for p in range(m)] for e in range(n)]
    utilites_parcours = [[n-1 - preferences_parcours[p].index(e) for e in range(n)] for p in range(m)]
    
    # Génération des paires (e,p) valides (k premiers choix)
    E = []
    for e in range(n):
        premiers_choix = preferences_etudiants[e][:k]
        for p in premiers_choix:
            E.append((e, p))
    
    with open(nom_fichier, "w") as f:
        # Fonction objectif - maximiser la somme des utilités
        f.write("maximize\n")
        termes = []
        for (e, p) in E:
            # Utilité totale = utilité étudiant + utilité parcours
            utilite_totale = utilites_etudiants[e][p] + utilites_parcours[p][e]
            termes.append(f"{utilite_totale} x{e}_{p}")
        f.write("  obj: " + " + ".join(termes) + "\n\n")
        
        f.write("subject to\n")
        
        # Chaque étudiant est affecté à exactement un parcours (parmi ses k premiers choix)
        for e in range(n):
            choix_possibles = [p for p in preferences_etudiants[e][:k]]
            constraint = " + ".join([f'x{e}_{p}' for p in choix_possibles])
            f.write(f"  c{e}: {constraint} = 1\n")
        
        # Respect des capacités des parcours
        for p in range(m):
            etudiants_possibles = [e for e, p_prime in E if p_prime == p]
            if etudiants_possibles:  # Si le parcours est dans les k premiers choix d'au moins un étudiant
                constraint = " + ".join([f'x{e}_{p}' for e in etudiants_possibles])
                f.write(f"  c{n+p}: {constraint} <= {capacites[p]}\n")
        
        # Les variables binaires
        f.write("\nBinary\n")
        for (e, p) in E:
            f.write(f"  x{e}_{p}\n")
        
        f.write("end\n")
    
    print(f"\nFichier {nom_fichier} généré avec succès.")


import re

def lire_solution_plne(nom_fichier):
    """
    Lit un fichier solution (.sol) et retourne un dictionnaire d'affectations.
    
    Args:
        nom_fichier (str): Chemin du fichier solution
        
    Returns:
        dict: Dictionnaire {parcours: [étudiants]} des affectations
    
    Format du fichier attendu:
        - Une ligne par variable
        - Format: x_e_p 1 où e est l'étudiant et p le parcours
        - Seules les variables à 1 sont considérées
    
    Exemple de ligne valide:
        x_1_2 1    # Étudiant 1 affecté au parcours 2
    """
    affectation = {}

    try:
        with open(nom_fichier, "r") as f:
            for ligne in f:
                # Ignorer les lignes de commentaires et les lignes vides
                if ligne.startswith('#') or not ligne.strip():
                    continue
                
                # Format de ligne attendu: x_e_p 1
                if ligne.strip().endswith('1'):
                    parts = re.split(r'[_\s]+', ligne.strip())
                    if len(parts) >= 3:
                        etudiant = int(parts[0][1:])
                        parcours = int(parts[1])
                        if parcours not in affectation:
                            affectation[parcours] = []
                        affectation[parcours].append(etudiant)
                        
        return affectation
        
    except FileNotFoundError:
        print(f"Erreur: Le fichier {nom_fichier} n'existe pas.")
        print("Pensez à modifier 'repo_path' dans le main monsieur :)")
        return None
    except Exception as e:
        print(f"Erreur lors de la lecture du fichier: {e}")
        return None
