#!/bin/bash

# Génère un nombre aléatoire entre 0 et 5
random_number=$((RANDOM % 6))

# Vérifie si le nombre aléatoire est égal à 0
if [ $random_number -eq 0 ]; then
  echo "You lost everything"
else
  echo "lucky boy !"
fi
