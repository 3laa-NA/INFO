// Fonction pour obtenir la valeur absolue d'un nombre
double valeur_absolue(double x){
    if(x < 0){
        return -x; // Retourne la valeur négative de x si x est négatif
    }
    return x; // Retourne x si x est positif ou nul
}

// Fonction pour calculer le nombre de chiffres significatifs communs entre x et y
double bitcommun(double x, double y) {
    double erreur_absolue = valeur_absolue(x - y); // Calcul de l'erreur absolue entre x et y
    double denominateur = valeur_absolue(x + y); // Calcul du denominateur pour Cxy
    double Cxy = 2 * erreur_absolue / denominateur; // Calcul de Cxy selon la formule donnée
    return -log(Cxy) / log(10); // Calcul du logarithme en base 10 de Cxy pour obtenir le nombre de chiffres significatifs communs
}
// Fonction optimisée pour calculer le nombre de chiffres significatifs communs entre x et y
int bitcommun_opt(double x, double y) {
    // Conversion des valeurs x et y en entiers
    long long intX = *(long long*)&x;
    long long intY = *(long long*)&y;
    
    // Calcul de la différence en valeurs entières
    long long diff = intX - intY;
    
    // Si la différence est négative, la convertir en positive
    if (diff < 0) {
        diff = -diff;
    }

    // Détermination du bit de poids le plus élevé de la différence
    int msb = 63; // Représente le bit de poids le plus élevé
    while (!(diff & (1LL << msb))) {
        msb--; // Décalage vers des bits moins significatifs jusqu'à ce que le bit de poids le plus élevé soit trouvé
    }

    // Calcul du nombre de chiffres significatifs communs en utilisant le bit de poids le plus élevé
    return msb + 1;
}