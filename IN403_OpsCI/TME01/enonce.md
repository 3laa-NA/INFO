# TME 1 OpsCI (4h)  
## Th&egrave;me : Bootstrapping + R&eacute;seau + Debug de service (pr&eacute;paration projet "FilmFinder")

### Objectifs p&eacute;dagogiques
&Agrave; la fin de ce TME, vous serez capable de :
- Vous connecter &agrave; une machine Linux et utiliser le terminal
- Manipuler des fichiers et des r&eacute;pertoires en ligne de commande
- Comprendre les notions d'interface r&eacute;seau, d'adresse IP et de port
- Observer et arr&ecirc;ter des processus
- Automatiser des commandes dans des scripts shell
- Produire un **system-report** reproductible

---

## Livrable (&agrave; rendre avant 26/01/2026 23h59)
D&eacute;posez **une seule archive** :
```
tme1_<nom>_<prenom>.zip
```
Elle devra contenir :
- `answers.md` : vos r&eacute;ponses et commandes utilis&eacute;es
- `system-report/` : fichiers g&eacute;n&eacute;r&eacute;s par vos scripts
- `scripts/collect.sh` : script de collecte syst&egrave;me
- `scripts/portlab.sh` : script mini-lab ports
- `README.md` : comment ex&eacute;cuter vos scripts

**Interdictions**
- Pas de donn&eacute;es sensibles (cl&eacute;s SSH priv&eacute;es, tokens, historiques complets)
- Pas de scan r&eacute;seau externe : uniquement `localhost` / votre VM

---

# Partie A: Prise en main du terminal et des fichiers <!-- (~ 1h15) -->

## A1. Connexion & identit&eacute; 
Dans `answers.md`, notez :
```bash
whoami
pwd
echo "$HOME"
cat /etc/os-release | head
```

## A2. R&eacute;cup&eacute;rer le "starter pack" du TME
T&eacute;l&eacute;chargez et d&eacute;compressez le fichier fourni par l'enseignant :

```bash
curl -L starter.zip -o starter.zip
unzip starter.zip
```

Ou :
```bash
wget starter.zip
unzip starter.zip
```

Puis explorez l'arborescence :
```bash
tree starter
```
Dans `answers.md`, expliquez en 2 lignes la diff&eacute;rence entre `curl` et `wget`.

## A3. Rechercher / copier / d&eacute;placer / supprimer 
Dans le dossier `starter/`, ex&eacute;cutez et copiez les commandes dans `answers.md` :

```bash
find starter -iname "*movie*"
find starter -type f -name "*.json"
cp starter/data/sample_movie.json workspace/
mv workspace workspace_backup
rm workspace_backup/sample_movie.json
```

Expliquez bri&egrave;vement la diff&eacute;rence entre `rm` et `rm -r`.

## A4. Droits 
Cr&eacute;ez et ex&eacute;cutez un script :
```bash
mkdir -p workspace/scripts
nano workspace/scripts/hello.sh
```
Contenu :
```bash
#!/bin/bash
echo "hello"
```
Puis :
```bash
chmod +x workspace/scripts/hello.sh
./workspace/scripts/hello.sh
```
Expliquez ce que fait `chmod +x`.

---

# Partie B: R&eacute;seau & ports 

## B1. Interfaces, IP, MAC 
```bash
ip a
ip r
```
Dans `answers.md`, expliquez :
- diff&eacute;rence entre `lo` et une interface r&eacute;seau r&eacute;elle
- diff&eacute;rence entre IP priv&eacute;e et IP publique

## B2. Ports en &eacute;coute 
```bash
ss -lntup
```
Ou :
```bash
lsof -i -P -n | grep LISTEN
```
Expliquez ce qu'est un **port** et la diff&eacute;rence TCP/UDP (2-3 lignes).

## B3. Mini-lab "ouvrir/fermer un service"

1. D&eacute;marrer un serveur HTTP :
```bash
python3 -m http.server 8080 --directory workspace &
```

2. V&eacute;rifier qu'il &eacute;coute :
```bash
ss -lntup | grep 8080
```

3. Tester :
```bash
curl -I http://localhost:8080
curl http://localhost:8080 | head
```

4. Trouver le PID et arr&ecirc;ter :
```bash
ps aux | grep http.server
kill <PID>
```

5. V&eacute;rifier fermeture :
```bash
curl http://localhost:8080
```

Notez toutes vos commandes et sorties pertinentes dans `answers.md`.

---

# Partie C: Processus & diagnostic <!--(~ 45 min)-->

## C1. Processus 
```bash
sleep 600 &
ps aux | grep sleep
kill <PID>
top -b -n 1 | head
```

## C2. Logs 
```bash
journalctl -xe | tail
```
Ou :
```bash
dmesg | tail
```
Expliquez en 2 lignes &agrave; quoi servent les logs.

---

# Partie D: Automatisation (scripts) 

## D1. `scripts/collect.sh`
Cr&eacute;ez `system-report/` et g&eacute;n&eacute;rez :
- `system-report/hw.txt` : CPU, RAM, disque
- `system-report/net.txt` : IP, routes, ports en &eacute;coute
- `system-report/proc.txt` : top 10 processus

Votre script doit &ecirc;tre relan&ccedil;able et propre.

## D2. `scripts/portlab.sh`
Le script doit :
- d&eacute;marrer un serveur HTTP sur 8080 en background
- v&eacute;rifier qu'il &eacute;coute
- faire un `curl`
- stopper le serveur
- v&eacute;rifier que le port est ferm&eacute;


## Pour les s&eacute;ances suivantes:

Dans les TME suivants, vous concevrez, d&eacute;velopperez, conteneuriserez et d&eacute;ploierez une application de **recommandation et recherche de films**.

**Vous &ecirc;tes libres de choisir votre stack technique**, parmi les options ci-dessous (ou une alternative &eacute;quivalente valid&eacute;e par l'enseignant).

---

### Front-end

- **Astro**  
  - Site tr&egrave;s rapide, "HTML-first", performant et SEO-friendly  
  - Adapt&eacute; aux pages de liste de films, recherche, fiches d&eacute;taill&eacute;es  

- **React + Vite**  
  - Standard entreprise pour applications web modernes (SPA)  
  - Tr&egrave;s large &eacute;cosyst&egrave;me et support industriel  

- **Angular**  
  - Framework complet, structur&eacute;, adapt&eacute; aux grands projets  
  - Bon pour le travail en &eacute;quipe et les projets maintenables  

- **Vue + Vite**  
  - Simple &agrave; prendre en main, clair et efficace  
  - Bon compromis entre simplicit&eacute; et puissance  

- **Svelte / SvelteKit**  
  - Tr&egrave;s performant, syntaxe proche du HTML  
  - L&eacute;ger et moderne  

---

### Back-end

- **FastAPI (Python)**  
  - Rapide &agrave; d&eacute;velopper, tr&egrave;s performant pour des API REST  
  - Typage clair, documentation automatique  

- **Node.js (Express ou NestJS)**  
  - Tr&egrave;s r&eacute;pandu en entreprise  
  - &Eacute;cosyst&egrave;me riche et flexible  

- **PHP (Laravel ou Symfony)**  
  - &Eacute;cosyst&egrave;me mature et bien document&eacute;  
  - Tr&egrave;s utilis&eacute; dans l'industrie  

- **ASP.NET Core (C#)**  
  - Tr&egrave;s performant, robuste et structur&eacute;  
  - Adapt&eacute; aux grandes applications professionnelles  

- **Go (Fiber ou Gin)**  
  - Tr&egrave;s rapide, l&eacute;ger et efficace pour les API  
  - Excellent pour les services conteneuris&eacute;s  

---

### Base de donn&eacute;es

#### SQL (relationnel)

- **PostgreSQL**  
  - Robuste, SQL avanc&eacute;, tr&egrave;s utilis&eacute; en production  
  - Bon support des transactions, index avanc&eacute;s et JSON  

- **MySQL / MariaDB**  
  - Simple, largement r&eacute;pandu, facile &agrave; administrer  
  - Tr&egrave;s utilis&eacute; pour des applications web classiques  

---

#### NoSQL (non relationnel) 

- **MongoDB (document)**  
  - Mod&egrave;le bas&eacute; sur des documents JSON  
  - Tr&egrave;s adapt&eacute; aux donn&eacute;es semi-structur&eacute;es  
  - Bonne int&eacute;gration avec Node.js et Python  

- **Redis (cl&eacute;-valeur, cache / base rapide)**  
  - Tr&egrave;s performant, faible latence  
  - Peut servir de cache ou de base principale pour certains cas  

- **Neo4j (graphe)**  
  - Adapt&eacute; aux recommandations et relations complexes  
  - Int&eacute;ressant pour mod&eacute;liser des liens "utilisateur <--> film <--> acteur <--> genre"  

- **Elasticsearch (recherche full-text)**  
  - Excellente recherche textuelle et filtrage avanc&eacute;  
  - Peut compl&eacute;ter une base principale pour la recherche de films  

---

### Orchestration et d&eacute;ploiement

Quel que soit votre choix de stack, vous devrez utiliser :

- **Docker**  
  - Conteneuriser s&eacute;par&eacute;ment :  
    - le front-end  
    - le back-end  
    - la base de donn&eacute;es  

- **Kubernetes**  
  - D&eacute;ployer votre application sur un cluster  
  - G&eacute;rer :  
    - Pods, Services, Ingress  
    - ConfigMaps et Secrets  
    - Mise &agrave; l'&eacute;chelle (scaling)  

---

### Exigences minimales du projet

Votre projet final devra comporter :

- Un d&eacute;p&ocirc;t **Git** (GitLab recommand&eacute;)
- Un pipeline **CI/CD** automatis&eacute; (build --> tests --> image Docker --> d&eacute;ploiement)
- Une architecture claire (sch&eacute;ma fourni dans le rapport final)
- Une documentation minimale (`README.md`) expliquant :
  - comment lancer l'application,
  - comment construire les images Docker,
  - comment d&eacute;ployer sur Kubernetes.

