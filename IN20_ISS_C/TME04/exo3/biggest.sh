#!/bin/bash

# Vérifier la présence du paramètre
if [ $# -ne 1 ]; then
  echo "Usage: $0 <nom_du_répertoire>"
  exit 1
fi

# Vérifier si le répertoire existe
if [ ! -d "$1" ]; then
  echo "Le répertoire '$1' n'existe pas."
  exit 1
fi

i=0
n=""


for file in "$1"/*; do

    size=$(wc -c < "$file")

    # Comparer les tailles
    if [ "$size" -gt "$i" ]; then
      i="$size"
      n="$file"
    fi

done

if [ -z "$n" ]; then
  echo "Aucun fichier trouvé dans le répertoire '$1'."
else
  echo "$n"
fi
