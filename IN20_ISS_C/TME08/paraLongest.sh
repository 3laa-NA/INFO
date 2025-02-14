#!/bin/bash

# Vérifiez la présence et la validité du répertoire en paramètre
if [ "$#" -ne 1 ] || [ ! -d "$1" ]; then
  echo "Usage: $0 <directory>"
  exit 1
fi

word=""

for file in "$1"/*; do
  
  ./longest.sh "$file" 

  if [ $(wc -c < "$file.tmp") -gt $(echo $word | wc -c) ]; then
    word=$(cat "$file.tmp")
  fi

done


echo $word