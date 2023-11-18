#! /bin/bash

#en cas d'appelle sans pârametre
if [ $# -lt 1 ]; then
    echo "Il manque un paramètre"
    echo "Usage : ./pere.sh <nb_fils>"
    exit -1; #on quitte le script
fi

printf "Je suis $$ \n"

i=$1 #ici on a le nombre de fils a créer
j=1  #ici on a le compteur

while [ $i -gt 0 ] ; do
    #on utilise le compteur pour afficher le rang
    printf "Fils $j : " 
    #on appelle fils.sh
    ./fils.sh
    i=$((i - 1))
    j=$((j + 1))

done