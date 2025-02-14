#!/bin/bash

# Fonction pour afficher l'usage du script
function usage() {
  echo "Usage: $0 <fichier_log>"
  exit 1
}

# Vérifier le nombre d'arguments
if [ $# -ne 1 ] ; then
  echo "Erreur : Nombre incorrect d'arguments."
  usage
fi


# Vérifier si le fichier existe et est lisible
if [ ! -f "$1" ] || [ ! -r "$1" ]; then
  echo "Erreur : Le fichier n'est pas accessible en lecture."
  usage
fi


num_entree=$(grep -c -v "reboot" "$1")
echo "Nombre d'entrée: $num_entree"

moi=$(whoami)
dernier=$(last -d | head -n 1 | cut -d ' ' -f 1)

if [ "$dernier" = "$moi" ]; then
  echo "Vous etes le dernier utilisateur."
else
  echo "Vous n'etes pas le dernier utilisateur"
fi

num_connexions=$(grep -c "$me" "$1")
echo "Nombre de connexions de l'utilisateur actuel ($moi): $num_connexions"


num_utilisateurs=$(cut -d ' ' -f 1 "$1" | sort -u | wc -l)
echo "Nombre d'utilisateurs : $num_utilisateurs"


num_machines_dis=$(grep -c -E '.*[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+|localhost' "$1")
echo "Nombre de machines distantes présentes dans la trace: $num_machines_dis"

utilisateurs_dis=$(grep -E '.*[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+|localhost' "$1" | cut -d ' ' -f 1 | sort -u)


for utilisateur in $utilisateurs_dis; do
  machine_dis=$(awk -v u="$utilisateur" '$1 == u && ($NF ~ /.*[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+|localhost/){print $NF}' "$1" | sort -u)
  echo "L'utilisateur $utilisateur s'est connecté à partir de la machine: $machines_di"
done


