#! /bin/bash

printf "Je suis $$ \n"

#boucle qui appelle fils.sh 10 foi
for i in {0..9}; do
    ./fils.sh
done