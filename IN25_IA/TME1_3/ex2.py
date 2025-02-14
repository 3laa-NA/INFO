"""
Module de génération de données et mesures de performance.

Fonctions:
- generer_pref_etudiants: Génère les préférences aléatoires des étudiants
- generer_pref_parcours: Génère les préférences aléatoires des parcours
- generer_capacites: Génère des capacités équilibrées pour les parcours
- mesurer_temps: Compare les performances des deux variantes de Gale-Shapley
"""
import random
import time
from ex1 import gale_shapley_etudiants, gale_shapley_parcours

def generer_pref_etudiants(n):
    """
    Génère une matrice CE où chaque étudiant a une liste de préférences aléatoires sur 9 parcours.
    
    Args:
        n (int): Nombre d'étudiants
    Returns:
        list: Matrice n×9 des préférences des étudiants
    
    Format:
        Retourne une liste de n listes, où chaque sous-liste est une permutation
        de [0,1,...,8] représentant l'ordre de préférence des 9 parcours.
    """
    nb_parcours = 9  # Nombre fixe de parcours
    # Création d'une liste de préférences aléatoires pour chaque étudiant
    C_e = [random.sample(range(nb_parcours), nb_parcours) for _ in range(n)]
    return C_e

def generer_pref_parcours(n):
    """
    Génère une matrice CP où chaque parcours a une liste de préférences aléatoires sur n étudiants.
    
    Args:
        n (int): Nombre d'étudiants
    Returns:
        list: Matrice 9×n des préférences des parcours
    """
    C_p = [random.sample(range(n), n) for _ in range(9)]
    return C_p


def generer_capacites(n):
    """
    Génère des capacités équilibrées pour 9 parcours avec une somme égale à n.
    
    Args:
        n (int): Nombre total d'étudiants à répartir
    
    Returns:
        list: Liste des 9 capacités avec une répartition équitable
              Les places restantes sont distribuées aux premiers parcours
    """
    base = n // 9
    capacites = [base] * 9
    for i in range(n % 9):  # Répartir les places restantes
        capacites[i] += 1
    return capacites

def mesurer_temps(n, repetitions=10):
    """
    Mesure le temps moyen d'exécution des deux variantes de Gale-Shapley.
    
    Args:
        n (int): Nombre d'étudiants/parcours à tester
        repetitions (int): Nombre de répétitions pour moyenner les résultats
    
    Returns:
        tuple: (temps_moyen_etudiants, temps_moyen_parcours)
               Temps moyens d'exécution en secondes pour chaque variante
    
    Processus:
    1. Génère des données aléatoires (préférences et capacités)
    2. Exécute les deux variantes de l'algorithme
    3. Mesure et moyenne les temps d'exécution
    """
    temps_etudiants = []
    temps_parcours = []
    
    for _ in range(repetitions):
        # Génération des données aléatoires
        CE = generer_pref_etudiants(n)
        CP = generer_pref_parcours(n)
        capacites = generer_capacites(n)
        
        # Test de performance côté étudiants
        start = time.time()
        gale_shapley_etudiants(CE, CP, capacites)
        temps_etudiants.append(time.time() - start)
        
        # Test de performance côté parcours
        start = time.time()
        gale_shapley_parcours(CE, CP, capacites)
        temps_parcours.append(time.time() - start)
    
    # Calcul des moyennes
    return sum(temps_etudiants) / repetitions, sum(temps_parcours) / repetitions
