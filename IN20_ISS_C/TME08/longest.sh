#!/bin/bash

# Vérifiez la présence du paramètre
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <filename>"
  exit 1
fi

# Vérifiez la lisibilité du fichier
if [ ! -r "$1" ]; then
  echo "Erreur: Le fichier n'est pas lisible."
  exit 1
fi

# Cherchez le mot le plus long dans le fichier

longest_word=""
max_length=0

while read -r word; do
  length=${#word}
  if [ $length -gt $max_length ]; then
    max_length=$length
    longest_word=$word
  fi
done < "$1"

# Écrivez le mot le plus long dans un nouveau fichier
echo $longest_word > "$1.tmp"

# echo "Le mot le plus long a été écrit dans $1.tmp"

