#!/bin/bash

# Vérifiez si le nombre d'arguments est correct
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <pid>"
  exit 1
fi

# Lancez ps chaque seconde jusqu'à ce que le processus devienne zombie ou disparaisse
while true; do
  # Utilisez la commande ps pour obtenir le statut du processus
  stat=$(ps --no-headers -o stat --pid $1)

  # Vérifiez si le processus est devenu zombie
  if [ "$stat" == "Z" ]; then
    echo "Le processus est devenu zombie !!!"
    exit 0
  fi

  # Vérifiez si le processus a disparu
  if ! ps -p $1 > /dev/null; then
    echo "Le processus a disparu."
    exit 0
  fi

  sleep 1
done
