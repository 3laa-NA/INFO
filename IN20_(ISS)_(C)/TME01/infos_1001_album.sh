printf "__________________________________________\n"

echo "Les albums recommandés des Beatles sont :"
printf "\n"
find 1001_Albums_You_Must_Hear_Before_You_Die -type f -name "John_Lennon-*-*" -printf "%f\n"
find 1001_Albums_You_Must_Hear_Before_You_Die -type f -name "George_Harrison-*-*" -printf "%f\n"
find 1001_Albums_You_Must_Hear_Before_You_Die -type f -name "Paul_McCartney-*-*" -printf "%f\n"
find 1001_Albums_You_Must_Hear_Before_You_Die -type f -name "Ringo_Starr-*-*" -printf "%f\n"

printf "\n__________________________________________\n"
echo "Les albums dont le nom est une simple lettre :"
printf "\n"
find 1001_Albums_You_Must_Hear_Before_You_Die -type f -name "*-[a-zA-Z]-*" 

printf "\n__________________________________________\n"
nombre_albums=$(find 1001_Albums_You_Must_Hear_Before_You_Die -type f -name "*-*-*" | wc -l)
echo "Le nombre total d'albums présents est : $nombre_albums"

nombre_caracters=$(find 1001_Albums_You_Must_Hear_Before_You_Die -type f -name "*-*-*" | wc -c)

moyenne=$(($nombre_caracters/$nombre_albums))

printf "\n__________________________________________\n"
echo "a moyenne des tailles des noms de fichiers des albums est : $moyenne"

printf "\n__________________________________________\n"
echo "graphique de la répartition de ces albums suivant les années (de 1995 à 2016) :"
printf "\n"

for i in {1995..2016}; do
    printf "$i : "
    find 1001_Albums_You_Must_Hear_Before_You_Die -type f -name "*-*-$i*" -printf "x"
    printf "\n"
done
