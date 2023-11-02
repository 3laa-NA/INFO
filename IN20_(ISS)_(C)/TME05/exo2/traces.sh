#!/bin/bash


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


# Fonction pour afficher l'usage du script
function usage() {
    echo "Usage: $0 <fichier_log>"
    exit 1
}

num_entries=$(grep -c -v "reboot" "$log_file")
echo "Number of entries in the trace: $num_entries"

last_user=$(whoami)
last_entry=$(last -d | grep -m 1 "$last_user")

if [ -n "$last_entry" ]; then
  echo "You are the last user to have connected."
else
  echo "You are not the last user to have connected."
fi

num_connections=$(grep -c "$last_user" "$log_file")
echo "Number of connections for $last_user: $num_connections"

unique_users=$(awk '{print $1}' "$log_file" | sort -u | wc -l)
echo "Number of unique users who have connected at least once: $unique_users"

num_remote_machines=$(grep -c -E '.*[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+|localhost' "$log_file")
echo "Number of remote machines in the trace: $num_remote_machines"

remote_users=$(awk '$NF ~ /.*[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+|localhost/{print $1}' "$log_file" | sort -u)

for user in $remote_users; do
  remote_machines=$(awk -v u="$user" '$1 == u && ($NF ~ /.*[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+|localhost/){print $NF}' "$log_file" | sort -u)
  echo "Machines from which $user has connected: $remote_machines"
done


# Le script continue ici
