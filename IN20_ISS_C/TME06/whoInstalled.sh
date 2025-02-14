#!/bin/bash

# Recherche de l'utilisateur avec UID 1000 dans /etc/passwd
utilisateur=$(grep "1000:" /etc/passwd | cut -d ':' -f1)

if [ -n "$utilisateur" ]; then
    echo "L'utilisateur qui a installé la machine est : $utilisateur"
else
    echo "Aucun utilisateur trouvé avec UID 1000."
fi
