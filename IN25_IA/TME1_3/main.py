"""
Programme principal d'affectation des étudiants aux parcours avec menu interactif.

Ce programme permet de:
1. Charger et visualiser les données de préférences
2. Exécuter les algorithmes de Gale-Shapley (versions étudiants et parcours)
3. Analyser la stabilité des affectations
4. Mesurer les performances des algorithmes
5. Générer et analyser des solutions PLNE

Structure du programme:
- Menu interactif avec options numérotées
- Fonctions d'affichage pour les résultats
- Gestion des entrées/sorties fichiers
- Visualisation graphique des performances

Utilisation:
    python main.py
    
Notes:
- Les fichiers de données doivent être dans le même répertoire
- Les formats supportés sont décrits dans la documentation des modules
"""
import os
import matplotlib.pyplot as plt
from ex1 import (lire_pref_etudiants, lire_pref_parcours, lire_capac_parcours,
                gale_shapley_parcours, gale_shapley_etudiants, trouver_paires_instables)
from ex2 import mesurer_temps
from ex3 import (generer_fichier_plne_k_premiers, generer_fichier_plne_max_utilite, 
                 generer_fichier_plne_max_utilite_k_premiers, lire_solution_plne)

def afficher_matrice(matrice, titre="Matrice"):
    """
    Affiche une matrice avec des indices pour les lignes et colonnes.
    Chaque ligne correspond à une sous-liste de la matrice.
    """
    print(f"\n{titre} :")
    print("     ", end="")  # Espace initial pour aligner les colonnes
    # Affiche les indices des colonnes
    for i in range(len(matrice[0])):
        print(f"{i:3}", end=" ")
    print("\n" + "   " + "-" * (4 * len(matrice[0]) + 2))  # Ligne de séparation

    # Affiche les lignes avec leur indice
    for i, ligne in enumerate(matrice):
        print(f"{i:2} |", end=" ")  # Indice de la ligne
        for elem in ligne:
            print(f"{elem:3}", end=" ")
        print() # Saut de ligne après chaque ligne de la matrice

def calculer_utilites(affectation, C_e, C_p):
    """
    Calcule les utilités moyennes et minimales pour les étudiants et les parcours.
    
    Args:
        affectation (dict): Dictionnaire {parcours: [étudiants]} des affectations
        C_e (list): Matrice des préférences des étudiants
        C_p (list): Matrice des préférences des parcours
        
    Returns:
        tuple: (utilite_moyenne_totale, utilite_min_etudiant, utilite_min_parcours)
    """
    n = len(C_e)  # nombre d'étudiants
    m = len(C_p)  # nombre de parcours
    
    utilites_etudiants = []
    utilites_parcours = []
    utilite_min_etudiant = float('inf')
    utilite_min_parcours = float('inf')
    
    # Pour chaque parcours et ses étudiants affectés
    for parcours, etudiants in affectation.items():
        # Calculer l'utilité pour les étudiants de ce parcours
        for etudiant in etudiants:
            # Utilité de l'étudiant
            rang_etu = C_e[etudiant].index(parcours)
            utilite_etu = m - 1 - rang_etu
            utilites_etudiants.append(utilite_etu)
            utilite_min_etudiant = min(utilite_min_etudiant, utilite_etu)
            
            # Utilité du parcours
            rang_parcours = C_p[parcours].index(etudiant)
            utilite_parc = n - 1 - rang_parcours
            utilites_parcours.append(utilite_parc)
            utilite_min_parcours = min(utilite_min_parcours, utilite_parc)
    
    # Calculer la moyenne totale
    if utilites_etudiants and utilites_parcours:
        utilite_totale = sum(utilites_etudiants) + sum(utilites_parcours)
        utilite_moyenne_totale = utilite_totale / (len(utilites_etudiants)*2)
        return utilite_totale, utilite_moyenne_totale, utilite_min_etudiant, utilite_min_parcours
    else:
        return 0, 0, 0, 0

def afficher_affectation(affectation, C_e=None, C_p=None):
    """
    Affiche l'affectation des étudiants aux parcours et les utilités si les préférences sont fournies.
    """
    # Affichage classique des affectations
    for parcours in sorted(affectation.keys()):
        etudiants = affectation[parcours]
        if etudiants:
            print(f"Parcours {parcours} : Étudiants {sorted(etudiants)}")
    
    # Calcul et affichage des utilités si les préférences sont fournies
    if C_e is not None and C_p is not None:
        util_totale, util_moyenne, util_min_etu, util_min_parc = calculer_utilites(affectation, C_e, C_p)
        print(f"\nUtilité totale : {util_totale}")
        print(f"Utilité moyenne globale : {util_moyenne:.2f}")
        print(f"Utilité minimale étudiant : {util_min_etu}")
        print(f"Utilité minimale parcours : {util_min_parc}")

def menu():
    """Affiche le menu principal et retourne le choix de l'utilisateur."""
    print("\nMenu:")
    print("1. Exécuter toutes les options")
    print("2. Afficher les données")
    print("   - Matrice des préférences des étudiants")
    print("   - Matrice des préférences des parcours")
    print("3. Gale-Shapley côté étudiants")
    print("   - Affiche l'affectation où les étudiants proposent")
    print("4. Gale-Shapley côté parcours")
    print("   - Affiche l'affectation où les parcours proposent")
    print("5. Analyse de stabilité")
    print("   - Vérifie les paires instables pour les deux versions")
    print("6. Test de performance")
    print("   - Compare les temps d'exécution des deux versions")
    print("   - Option d'affichage graphique des résultats")
    print("7. Génération fichier PLNE k")
    print("   - Crée un fichier PL pour les k premiers choix")
    print("8. Génération PLNE utilités")
    print("   - Crée un fichier PL maximisant l'utilité totale")
    print("9. Génération PLNE utilités avec k premiers choix")
    print("   - Maximise l'utilité en limitant aux k premiers choix")
    print("10. Analyser solutions PLNE")
    print("    - Analyse la stabilité des solutions .sol")
    print("0. Quitter")
    return input("\nVotre choix : ")

def main():
    # Chargement initial des données
    C_e = lire_pref_etudiants("PrefEtu.txt")
    C_p = lire_pref_parcours("PrefSpe.txt")
    cap = lire_capac_parcours("PrefSpe.txt")
    
    while True:
        choix = menu()
        
        if choix == "0":
            print("Au revoir!")
            break
            
        if choix == "2" or choix == "1":
            print("\n=== Affichage des données ===")
            afficher_matrice(C_e, "Preferences des étudiants")
            afficher_matrice(C_p, "Preferences des parcours")
            
        if choix == "3" or choix == "1":
            print("\n=== Gale-Shapley côté étudiants ===")
            resultatEtu = gale_shapley_etudiants(C_e, C_p, cap)
            print("\nRésultat des affectations côté Étudiants:")
            afficher_affectation(resultatEtu, C_e, C_p)
                
        if choix == "4" or choix == "1":
            print("\n=== Gale-Shapley côté parcours ===")
            resultatParc = gale_shapley_parcours(C_e, C_p, cap)
            print("\nRésultat des affectations Parcours:")
            afficher_affectation(resultatParc, C_e, C_p)
                
        if choix == "5" or choix == "1":
            print("\n=== Analyse de stabilité ===")
            resultatEtu = gale_shapley_etudiants(C_e, C_p, cap)
            resultatParc = gale_shapley_parcours(C_e, C_p, cap)
            print("\nPaires instables pour l'affectation côté étudiants:", 
                  trouver_paires_instables(resultatEtu, C_e, C_p))
            print("Paires instables pour l'affectation côté parcours:", 
                  trouver_paires_instables(resultatParc, C_e, C_p))
                
        if choix == "6" or choix == "1":
            print("\n=== Test de performance ===")
            valeurs_n = list(range(200, 2001, 200))
            temps_moyens_etudiants = []
            temps_moyens_parcours = []
            
            for n in valeurs_n:
                temps_etud, temps_parc = mesurer_temps(n)
                temps_moyens_etudiants.append(temps_etud)
                temps_moyens_parcours.append(temps_parc)
                print(f"n = {n} → Étudiants: {temps_etud:.4f}s | Parcours: {temps_parc:.4f}s")
            
            if choix != "1":  # Ne pas demander pour l'option 1
                afficher_graph = input("\nVoulez-vous afficher le graphique ? (o/n) : ")
            else:
                afficher_graph = 'o'  # Toujours afficher pour l'option 1
                
            if afficher_graph.lower() == 'o':
                plt.figure(figsize=(10, 5))
                plt.plot(valeurs_n, temps_moyens_etudiants, marker='o', label="Gale-Shapley (étudiants)")
                plt.plot(valeurs_n, temps_moyens_parcours, marker='s', label="Gale-Shapley (parcours)")
                plt.xlabel("Nombre d'étudiants (n)")
                plt.ylabel("Temps moyen (s)")
                plt.title("Temps de calcul des algorithmes de Gale-Shapley")
                plt.legend()
                plt.grid()
                plt.show()
            
        if choix == "7" or choix == "1":
            print("\n=== Génération fichier PLNE K===")
            k = 5 if choix == "1" else int(input("Nombre de premiers choix à considérer (k) : "))
            generer_fichier_plne_k_premiers(C_e, cap, k, f"pl_{k}_premiers.lp")
            
        if choix == "8" or choix == "1":
            print("\n=== Génération PLNE utilités ===")
            generer_fichier_plne_max_utilite(C_e, C_p, cap, "pl_utilites.lp")
            
        if choix == "9" or choix == "1":
            print("\n=== Génération PLNE utilités avec k premiers choix ===")
            k = 5 if choix == "1" else int(input("Nombre de premiers choix à considérer (k) : "))
            generer_fichier_plne_max_utilite_k_premiers(C_e, C_p, cap, k, f"pl_utilites_{k}.lp")
            
        if choix == "10":
            print("\n=== Analyse des solutions PLNE ===")
            nom_fichier = input("Entrez le nom du fichier solution à analyser : ")
            repo_path = "/home/alaana/INFO-main/IN25_IA/TME1_3"
            full_path = os.path.join(repo_path, nom_fichier)
            affectation = lire_solution_plne(full_path)
            if affectation:
                print(f"\nAffectation du fichier {nom_fichier}:")
                afficher_affectation(affectation, C_e, C_p)
                paires_instables = trouver_paires_instables(affectation, C_e, C_p)
                if paires_instables:
                    print("\nPaires instables (p, etu):", paires_instables)
                    print(f"Nombre de paires instables: {len(paires_instables)}")
                else:
                    print("\nLa solution est stable (aucune paire instable)")
    
        if choix not in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"]:
            print("Option invalide!")
            
        if choix != "1":  # Ne pas attendre si on exécute toutes les options
            input("\nAppuyez sur Entrée pour continuer...")

if __name__ == "__main__":
    main()