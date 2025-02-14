#!/bin/bash

# Vérifiez si le nombre d'arguments est correct
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <pid>"
  exit 1
fi

# Lancez ps chaque seconde pendant une minute pour surveiller le processus
for i in {1..60}; do
  ps o pid,ppid,state --pid $1
  sleep 1
done
