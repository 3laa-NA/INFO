# créer un tableau pour stocker les nombres
a=()

while true; do
    #on crée la variable pour stcoker la valeur entrée
    v=""
    printf "Saisissez un nombre ou 'q' pour quitter : "
    read v

    #condition d'arret
    if [ $v = q ]; then
        break
    fi

    # ajouter le nombre donné au tableau
    a+=("$v")

    # message de confirmation
    printf "Vous avez ajouté $v à la somme\n"

done

#appelle à somme.c
./somme "${a[@]}"