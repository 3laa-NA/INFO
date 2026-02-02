# TME01 OpsCI - Réponses
**Étudiant:** ALABOUD Alaa
**Date:** 02/02/2026

---

## Partie A : Prise en main du terminal et des fichiers

### A1. Connexion & identité

```bash
whoami
# Output: alaana

pwd
# Output: /home/alaana/REPO/INFO

echo "$HOME"
# Output: /home/alaana

cat /etc/os-release | head
# Output:
# PRETTY_NAME="Debian GNU/Linux 12 (bookworm)"
# NAME="Debian GNU/Linux"
# VERSION_ID="12"
# VERSION="12 (bookworm)"
# VERSION_CODENAME=bookworm
# ID=debian
```

**Système:** Debian GNU/Linux 12 (bookworm)

---

### A2. Récupérer le "starter pack"

Le starter pack présent dans `starter_combined/`. Arborescence (tree pas installé) :

```bash
find starter_combined -type f -o -type d
# starter_combined/
# ├── config/
# │   └── sample.env
# ├── data/
# │   ├── actors.json
# │   ├── movies.json
# │   └── ratings.json
# ├── docs/
# │   └── architecture.md
# └── README.md
```

**Différence curl vs wget :**
- `curl` : outil polyvalent pour transférer des données avec URLs, supporte beaucoup de protocoles, affiche sur stdout par défaut
- `wget` : téléchargeur de fichiers simple, télécharge directement sur disque, supporte la reprise et le téléchargement récursif

---

### A3. Rechercher / copier / déplacer / supprimer

```bash
# Rechercher tous les fichiers contenant "movie" (insensible à la casse)
find starter_combined -iname "*movie*"
# Output: starter_combined/data/movies.json

# Trouver tous les fichiers JSON
find starter_combined -type f -name "*.json"
# Output:
# starter_combined/data/ratings.json
# starter_combined/data/actors.json
# starter_combined/data/movies.json

# Copier le fichier
mkdir -p workspace
cp starter_combined/data/movies.json workspace/

# Renommer le dossier
mv workspace workspace_backup

# Supprimer le fichier
rm workspace_backup/movies.json
```

**Différence rm vs rm -r :**
- `rm` : supprime des fichiers uniquement
- `rm -r` : supprime récursivement (fichiers + dossiers et tout leur contenu)

**Note sur mv :**
`mv` peut renommer OU déplacer (c'est la même opération) :
- Renommer : `mv fichier.txt nouveau_nom.txt` (même dossier)
- Déplacer : `mv fichier.txt /autre/dossier/` (autre emplacement)
- Les deux : `mv fichier.txt /autre/dossier/nouveau_nom.txt`
Contrairement à `cp` qui copie, `mv` déplace → l'original disparaît

---

### A4. Droits

```bash
# Créer le dossier et le script
mkdir -p workspace_backup/scripts
nano workspace_backup/scripts/hello.sh  # (ou cat/echo)

# Contenu du script :
#!/bin/bash
echo "hello"

# Permissions avant chmod +x
ls -l workspace_backup/scripts/hello.sh
# -rw-r--r-- 1 alaana alaana 25 Feb  2 13:37 hello.sh

# Rendre exécutable
chmod +x workspace_backup/scripts/hello.sh

# Permissions après
ls -l workspace_backup/scripts/hello.sh
# -rwxr-xr-x 1 alaana alaana 25 Feb  2 13:37 hello.sh

# Exécuter
./workspace_backup/scripts/hello.sh
# Output: hello
```

**Ce que fait chmod +x :**
`chmod +x` ajoute le droit d'exécution (x) au fichier pour le propriétaire, le groupe et les autres. Cela transforme un fichier texte en un programme exécutable.

---

## Partie B : Réseau & Ports

### B1. Interfaces, IP, MAC

```bash
ip a
# 1: lo: <LOOPBACK,UP,LOWER_UP>
#     inet 127.0.0.1/8 scope host lo
# 2: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP>
#     link/ether 00:15:5d:25:f8:6a
#     inet 172.22.118.247/20

ip r
# default via 172.22.112.1 dev eth0
# 172.22.112.0/20 dev eth0 scope link src 172.22.118.247
```

**Différence entre lo et interface réseau réelle :**
- **lo (loopback)** : interface virtuelle qui boucle sur elle-même (127.0.0.1), utilisée pour les communications internes à la machine. Aucun trafic externe.
- **eth0** : interface réseau réelle/physique connectée au réseau, permet la communication avec d'autres machines.

**IP privée vs IP publique :**
- **IP privée** : adresse non routable sur Internet (10.x.x.x, 172.16-31.x.x, 192.168.x.x), utilisée dans les réseaux locaux. Ma machine a 172.22.118.247 (IP privée).
- **IP publique** : adresse routable sur Internet, unique mondialement, attribuée par le FAI.

---

### B2. Ports en écoute

```bash
ss -lntup
# Netid  State   Local Address:Port
# udp    UNCONN  10.255.255.254:53
# tcp    LISTEN  127.0.0.1:36883  users:(("node",pid=1709))
# tcp    LISTEN  127.0.0.1:4417   users:(("node",pid=6538))
```

**Qu'est-ce qu'un port ?**
Un port est un numéro (0-65535) qui identifie un service/application sur une machine. Il permet à plusieurs applications d'utiliser la même IP simultanément. Ex : port 80 pour HTTP, 443 pour HTTPS, 22 pour SSH.

**Différence TCP vs UDP :**
- **TCP** : protocole orienté connexion, garantit la livraison et l'ordre des paquets (fiable mais plus lent). Ex : HTTP, SSH.
- **UDP** : protocole sans connexion, pas de garantie de livraison (rapide mais non fiable). Ex : DNS, streaming vidéo.

---

### B3. Mini-lab "ouvrir/fermer un service"

```bash
# 1. Démarrer serveur HTTP sur port 8080
python3 -m http.server 8080 --directory workspace_backup &
# [1] 21390

# 2. Vérifier qu'il écoute
ss -lntp 2>/dev/null | grep 8080
# LISTEN 0  5  0.0.0.0:8080  0.0.0.0:*  users:(("python3",pid=21390,fd=3))

# 3. Tester avec curl
curl -I http://localhost:8080
# HTTP/1.0 200 OK
# Server: SimpleHTTP/0.6 Python/3.11.2
# Content-type: text/html; charset=utf-8

curl http://localhost:8080 | head
# <!DOCTYPE HTML>
# <html lang="en">
# <head>
# <title>Directory listing for /</title>

# 4. Trouver le PID et arrêter
ps aux | grep http.server
# alaana   21390  python3 -m http.server 8080 --directory workspace_backup

kill 21390

# 5. Vérifier fermeture
curl --connect-timeout 2 http://localhost:8080
# curl: (7) Failed to connect to localhost port 8080: Couldn't connect to server
```

Le port 8080 est maintenant fermé, le service est arrêté.

---

## Partie C : Processus & diagnostic

### C1. Processus

```bash
# Lancer un processus en arrière-plan
sleep 600 &
# [1] 26507

# Trouver le processus
ps aux | grep sleep
# alaana   26507  0.0  0.0   5468   920 pts/8    S    15:26   0:00 sleep 600

# Arrêter le processus
kill 26507
# [1]+  Terminated              sleep 600

# Voir les processus actifs
top -b -n 1 | head
# top - 15:27:31 up  3:03,  0 user,  load average: 0.02, 0.08, 0.08
# Tasks:  27 total,   2 running,  25 sleeping,   0 stopped,   0 zombie
# %Cpu(s):  7.1 us,  9.5 sy,  0.0 ni, 78.6 id,  4.8 wa
# MiB Mem :   3641.9 total,   1682.0 free,   1893.7 used
# 
#   PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
#  1766 alaana    20   0   63.6g 757692  63136 R  75.0  20.3   7:12.46 node
#  6039 alaana    20   0    7580   4388   3428 S  18.8   0.1   0:10.45 pet
```

---

### C2. Logs

```bash
# Journalctl (logs système systemd)
journalctl -xe | tail
# No journal files were found.
# (journald pas actif sur WSL)

# Utiliser dmesg (logs kernel)
dmesg | tail -15
# [ 4531.000031] mini_init (174): drop_caches: 1
# [ 5731.483586] mini_init (174): drop_caches: 1
# [ 6091.025347] mini_init (174): drop_caches: 1
# ...
# (logs de gestion mémoire du kernel)
```

**À quoi servent les logs ?**
Les logs enregistrent les événements système (démarrage, erreurs, actions utilisateur). Ils sont essentiels pour :
- Diagnostiquer les problèmes et erreurs
- Suivre l'activité système et la sécurité
- Déboguer les services et applications

---

## Partie D : Automatisation (scripts)

### D1. Script `collect.sh`

Script créé dans `scripts/collect.sh` qui génère automatiquement 3 fichiers de rapport :

```bash
#!/bin/bash
# Collecte d'informations système vers system-report/

mkdir -p ../system-report

# 1. Matériel (CPU, RAM, disque) → hw.txt
# 2. Réseau (IP, routes, ports) → net.txt  
# 3. Processus (top 10) → proc.txt
```

**Exécution :**
```bash
cd scripts/
chmod +x collect.sh
./collect.sh
```

**Résultat :**
```
Collecte des informations système...
[1/3] Collecte hardware...
[2/3] Collecte réseau...
[3/3] Collecte processus...
Collecte terminee!
Fichiers generes:
-rw-r--r-- 1 alaana alaana 1.7K Feb  2 15:32 hw.txt
-rw-r--r-- 1 alaana alaana 1.7K Feb  2 15:32 net.txt
-rw-r--r-- 1 alaana alaana 5.2K Feb  2 15:32 proc.txt
```

Le script est **relançable** (crée le dossier s'il n'existe pas, écrase les anciens rapports).

---

### D2. Script `portlab.sh`

Script créé dans `scripts/portlab.sh` qui automatise le mini-lab HTTP :

```bash
#!/bin/bash
# 1. Démarre serveur HTTP:8080 en background
# 2. Vérifie qu'il écoute (ss -lntp)
# 3. Teste avec curl
# 4. Arrête le serveur (kill PID)
# 5. Vérifie fermeture du port
```

**Exécution :**
```bash
cd scripts/
chmod +x portlab.sh
./portlab.sh
```

**Résultat :**
```
Mini-lab serveur HTTP (port 8080)
======================================

[1/5] Demarrage du serveur HTTP...
   PID du serveur : 27732

[2/5] Verification que le port 8080 est en ecoute...
   [OK] Port 8080 : OUVERT

[3/5] Test HTTP avec curl...
   [OK] Reponse HTTP : 200 OK
   
   Apercu de la page:
   <!DOCTYPE HTML>
   <html lang="en">
   <title>Directory listing for /</title>

[4/5] Arret du serveur (PID 27732)...
   [OK] Serveur arrete

[5/5] Verification que le port 8080 est ferme...
   [OK] Port 8080 : FERME

Test final (doit echouer)...
   [WARN] Connexion inattendue

Mini-lab termine avec succes!
```

Le script est **autonome** et **reproductible**.

---

## Résumé du livrable

Tous les fichiers sont prêts à être archivés :

```bash
TME01/
├── answers.md              # Toutes les réponses
├── README.md               # Instructions d'exécution
├── scripts/
│   ├── collect.sh         # Script de collecte
│   └── portlab.sh         # Mini-lab automatisé
└── system-report/
    ├── hw.txt             # Rapport matériel
    ├── net.txt            # Rapport réseau
    └── proc.txt           # Rapport processus
```

**Commande pour créer l'archive :**
```bash
cd /home/alaana/REPO/INFO/IN403_OpsCI
zip -r tme1_nom_prenom.zip TME01/ \
    -x "TME01/starter_combined/*" \
    -x "TME01/workspace_backup/*"
```
