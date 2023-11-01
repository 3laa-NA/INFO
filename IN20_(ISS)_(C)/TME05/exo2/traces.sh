#!/bin/bash


# Vérifier le nombre d'arguments
if [ $# -ne 1 ] ; then
    echo "Erreur : Nombre incorrect d'arguments."
    usage
fi


# Vérifier si le fichier existe et est lisible
if [ ! -f "$1" ] || [ ! -r "$1" ]; then
    echo "Erreur : Le fichier n'est pas accessible en lecture."
    usage
fi


# Fonction pour afficher l'usage du script
function usage() {
    echo "Usage: $0 <fichier_log>"
    exit 1
}


# Le script continue ici
