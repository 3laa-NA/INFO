# TME01 OpsCI - Bootstrapping + Réseau + Debug

**Étudiant :** alaana  
**Date :** 02/02/2026  
**Système :** Debian GNU/Linux 12 (bookworm)

---

## Structure du projet

```
TME01/
├── answers.md              # Réponses aux questions + commandes
├── README.md               # Ce fichier
├── enonce.md              # Énoncé du TME
├── scripts/
│   ├── collect.sh         # Script de collecte système
│   └── portlab.sh         # Mini-lab automatisé HTTP
├── system-report/         # Rapports générés
│   ├── hw.txt            # Infos matériel (CPU, RAM, disque)
│   ├── net.txt           # Infos réseau (IP, ports)
│   └── proc.txt          # Infos processus
└── workspace_backup/      # Dossier de test
    └── scripts/
        └── hello.sh       # Script hello basique
```

---

## Exécution des scripts

### 1. Script de collecte système (`collect.sh`)

Génère un rapport complet du système dans `system-report/`.

```bash
cd scripts/
./collect.sh
```

**Fichiers générés :**
- `system-report/hw.txt` : CPU, RAM, disque, OS
- `system-report/net.txt` : interfaces, IP, routes, ports en écoute
- `system-report/proc.txt` : top 10 processus par CPU/RAM

---

### 2. Mini-lab HTTP automatisé (`portlab.sh`)

Automatise le cycle de vie d'un serveur HTTP :
1. Démarre un serveur sur le port 8080
2. Vérifie qu'il écoute
3. Teste avec `curl`
4. Arrête le serveur
5. Vérifie la fermeture du port

```bash
cd scripts/
./portlab.sh
```

**Prérequis :** Python 3 installé

---

## Contenu du livrable

Pour créer l'archive à rendre :

```bash
cd /home/alaana/REPO/INFO/IN403_OpsCI
zip -r tme1_<nom>_<prenom>.zip TME01/ \
    -x "TME01/starter_combined/*" \
    -x "TME01/workspace_backup/*" \
    -x "TME01/.DS_Store"
```

**Contenu :**
- `answers.md` : toutes les réponses et commandes
- `system-report/` : rapports générés (hw.txt, net.txt, proc.txt)
- `scripts/collect.sh` : script de collecte
- `scripts/portlab.sh` : mini-lab automatisé
- `README.md` : instructions d'exécution

---

## Commandes utiles

```bash
# Rendre les scripts exécutables
chmod +x scripts/*.sh

# Lancer la collecte système
./scripts/collect.sh

# Lancer le mini-lab
./scripts/portlab.sh

# Consulter les rapports
cat system-report/hw.txt
cat system-report/net.txt
cat system-report/proc.txt
```

---

## ✅ Checklist TME

- [x] A1 : Identité système
- [x] A2 : Starter pack exploré
- [x] A3 : Manipulation fichiers (find, cp, mv, rm)
- [x] A4 : Droits et chmod +x
- [x] B1 : Interfaces réseau (ip a, ip r)
- [x] B2 : Ports en écoute (ss -lntup)
- [x] B3 : Mini-lab serveur HTTP manuel
- [x] C1 : Processus (sleep, ps, kill, top)
- [x] C2 : Logs (dmesg)
- [x] D1 : Script collect.sh
- [x] D2 : Script portlab.sh

---

## 📚 Notions apprises

- **Terminal Linux** : navigation, manipulation fichiers
- **Permissions** : chmod, droits d'exécution
- **Réseau** : interfaces (lo vs eth0), IP privée/publique, ports TCP/UDP
- **Processus** : lancement background (&), kill, monitoring
- **Automatisation** : scripts bash, collecte d'infos système
- **Debugging** : logs système, analyse de services
