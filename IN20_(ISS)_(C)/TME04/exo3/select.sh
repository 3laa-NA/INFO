#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Usage: $0 <nom_du_répertoire>"
  exit 1
fi

for i in {1..4}; do
mv $(./biggest.sh "$1") sélection/
done