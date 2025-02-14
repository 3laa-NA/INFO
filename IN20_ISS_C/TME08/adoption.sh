#!/bin/bash

# Lancement d'un processus
sleep 30 &

echo "Processus initial avec PID: $!"

# Attendre un peu pour observer l'adoption
sleep 5

# Utiliser la commande ps pour afficher les informations sur le processus
ps o pid,ppid,state --pid $!
