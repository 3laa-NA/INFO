#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Usage: $0 <pid>"
  exit 1
fi

# Vérifier le nombre d'arguments
if [ $# -ne 1 ] ; then
  echo "Erreur : Nombre incorrect d'arguments."
  usage
fi

pid="$1"

if [ ! -d "/proc/$pid" ]; then
  echo "Le PID ne correspond pas au pid d'un processus existant"
  exit 1
fi

# Fonction pour obtenir le nom d'un processus à partir de son PID
get_process_name() {
  local pid=$1
  local name

  if [ -f "/proc/$pid/comm" ]; then
    name=$(cat "/proc/$pid/comm")
  else
    name="Unknown"
  fi

  echo "$name"
}

while [ "$pid" -ne 1 ]; do
  parent_pid=$(cat "/proc/$pid/stat" | cut -d ' ' -f 4)
  process_name=$(get_process_name "$pid")
  echo "PID: $pid, Name: $process_name"
  pid="$parent_pid"
done

process_name=$(get_process_name "$pid")
echo "PID: $pid, Name: $process_name"
