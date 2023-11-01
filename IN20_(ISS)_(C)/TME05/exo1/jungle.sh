#!/bin/bash


echo "Choisissez la langue (VF ou VO) :"
read langue

# Vérifie si l'utilisateur a saisi VF ou VO
if [ "$langue" != "VF" ] && [ "$langue" != "VO" ]; then
    echo "Langue non reconnue. Utilisez VF ou VO."
    exit 1
fi

# Définir le séparateur de champ pour le fichier CSV
IFS=","


while read -r animal cri_fr cri_en; do
    if [ "$langue" == "VF" ]; then
        cowsay -f $animal "$cri_fr"
    else
        cowsay -f $animal "$cri_en"
    fi
done < "blabla.csv"
