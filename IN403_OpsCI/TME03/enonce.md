# TME 3: Utiliser une API r&eacute;elle + collecte de donn&eacute;es (scraping / export)

## Important: Continuit&eacute; avec le TME 2

**Si vous n'avez pas termin&eacute; le TME 2**, vous pouvez et devez **continuer &agrave; le finaliser** pendant ce TME.

Le TME 3 est con&ccedil;u :
- **en priorit&eacute; pour les groupes qui souhaitent aller plus loin** ;
- comme une **extension avanc&eacute;e** du travail d&eacute;j&agrave; r&eacute;alis&eacute; (API interne --> API r&eacute;elle).

Il n'est pas p&eacute;nalisant de ne pas terminer toutes les parties avanc&eacute;es du TME 3.
L'objectif est avant tout la **progression**, la **compr&eacute;hension** et la **qualit&eacute; de la d&eacute;marche**.

---

## Environnement de travail recommand&eacute; (&agrave; partir du TME 3)

&Agrave; partir de ce TME (et TME 2 aussi), le travail doit &ecirc;tre r&eacute;alis&eacute; sur une **machine virtuelle Linux**.

### Machines virtuelles disponibles en salle

Des machines sont disponibles dans les salles :
- **14-15-301**
- **14-15-401**

**Id&eacute;alement**, chaque bin&ocirc;me :
- choisit **une machine** ;
- l'utilise **pour tous les TME du module et pour le projet**.

Cela permet :
- un environnement stable ;
- moins de probl&egrave;mes de configuration ;
- une continuit&eacute; du travail.

### Instructions pour la connexion r&eacute;seau et l'installation de paquets sur les VM des salles

Pour pouvoir acc&eacute;der &agrave; Internet et installer des paquets (`apt`, `pip`, etc.) depuis les **machines virtuelles des salles**, il est n&eacute;cessaire de **configurer le proxy**.

Cette configuration doit &ecirc;tre effectu&eacute;e **&agrave; deux niveaux**.

---

#### 1. Configuration du proxy au niveau du syst&egrave;me (interface graphique)

1. Ouvrir les **Param&egrave;tres** du syst&egrave;me.
2. Aller dans :  
   **R&eacute;seau --> Proxy**.
3. Activer le proxy (**ON**).
4. Choisir le mode de configuration **Manuelle**.
5. Renseigner les champs suivants :

| Champ        | URL   | Port    |
|-------------|--------|---------|
| HTTP Proxy  | `proxy` | `3128` |
| HTTPS Proxy | `proxy` | `3128` |
| FTP Proxy   | `proxy` | `3128` |
| SOCKS Host  | `proxy` | `3128` |


---

#### 2. Configuration du proxy pour `apt`

Afin de permettre l'installation de paquets via `apt`, il est n&eacute;cessaire de configurer le proxy c&ocirc;t&eacute; gestionnaire de paquets.

##### &Eacute;tapes &agrave; suivre

1. Ouvrir un terminal.
2. Cr&eacute;er (ou &eacute;diter) le fichier suivant :

```bash
sudo nano /etc/apt/apt.conf.d/proxyPerso.conf
```

3. Ajouter la ligne suivante dans le fichier :

```conf
Acquire::http::proxy "http://proxy:3128/";
```

4. Enregistrer le fichier et quitter l'&eacute;diteur.

---

#### 3. V&eacute;rification

Tester la configuration avec la commande suivante :

```bash
sudo apt update
```

Si la configuration est correcte, la mise &agrave; jour de la liste des paquets doit fonctionner sans erreur r&eacute;seau.

---

### Remarque

Cette configuration est sp&eacute;cifique aux **machines virtuelles des salles** utilisant le proxy de Sorbonne Universit&eacute;.  
Elle peut &ecirc;tre adapt&eacute;e ou supprim&eacute;e si vous travaillez sur une machine personnelle ou en dehors du r&eacute;seau universitaire.

Vous trouverez plus d'informations sur la configuration du proxy sous Ubuntu sur la page suivante: https://doc.ubuntu-fr.org/proxy_terminal

---

## Travailler depuis chez soi (acc&egrave;s distant aux machines de la ppti)

Vous pouvez acc&eacute;der aux machines des salles **&agrave; distance**, depuis chez vous.

### Connexion SSH (mode terminal)

```bash
ssh numero_etudiant@ssh.ufr-info-p6.jussieu.fr
```

Puis, une fois connect&eacute; :

```bash
ssh numero_etudiant@ppti-14-301-P
```

ou

```bash
ssh numero_etudiant@ppti-14-15-401-P
```

o&ugrave; **P correspond au num&eacute;ro du PC** utilis&eacute; dans la salle.

---

### Connexion SSH avec affichage graphique (recommand&eacute; pour les VM)

Pour pouvoir :
- lancer une machine virtuelle,
- avoir un affichage graphique,

utilisez l'option `-X` :

```bash
ssh -X numero_etudiant@ssh.ufr-info-p6.jussieu.fr
```

Puis :

```bash
ssh -X numero_etudiant@ppti-14-301-P
```

ou

```bash
ssh -X numero_etudiant@ppti-14-15-401-P
```

Le `-X` est indispensable pour l'affichage graphique &agrave; distance.

---

## Cas des &eacute;tudiants utilisant leur propre machine

Vous pouvez utiliser **votre propre ordinateur**, ce qui offre plus de flexibilit&eacute;
(travail &agrave; domicile, confort personnel).

**Cependant**, vous devez alors :
- installer un logiciel de virtualisation (ex. **VirtualBox**) ;
- installer une **machine virtuelle Linux** :
  - Ubuntu,
  - Debian,
  - ou toute autre distribution &eacute;quivalente.

Le projet et les TME doivent &ecirc;tre r&eacute;alis&eacute;s **dans la machine virtuelle**, et non directement sur l'OS h&ocirc;te.

-------
-------

**La suite du TME 3 portera sur :**
- l'utilisation concr&egrave;te d'une **API r&eacute;elle** (TMDB) ;
- l'adaptation de votre back-end et front-end ;
- la **collecte et l'export de donn&eacute;es** ;
- une r&eacute;flexion sur le **scraping**, sa l&eacute;galit&eacute; et ses limites.

## Objectif

L'objectif de ce TME est d'apprendre &agrave; travailler comme en entreprise :
- int&eacute;grer une **API publique r&eacute;elle** (lecture de documentation, authentification, endpoints, erreurs) ;
- adapter votre **back-end** et votre **front-end** pour consommer cette API proprement ;
- mettre en place une **collecte de donn&eacute;es** (extraction / sauvegarde / formats) ;
- comprendre les notions de **l&eacute;galit&eacute;, conditions d'utilisation, &eacute;thique** et bonnes pratiques.

&Agrave; la fin de ce TME, vous devez avoir :
- une application capable d'afficher un catalogue de films aliment&eacute; par une **API externe** ;
- un back-end qui joue un r&ocirc;le d'**API proxy / agr&eacute;gateur** ;
- une collecte/export de donn&eacute;es (JSON/CSV/XML/...) ;
- un rapport enrichi (sources + justification + limites + risques).

API utilis&eacute;e :
- Documentation : https://developer.themoviedb.org/docs/getting-started

---

## Partie 1: Prise en main d'une API r&eacute;elle (TMDB)


### 1.1 Objectif

Comprendre comment on int&egrave;gre une API publique :
- lire la documentation ;
- obtenir une cl&eacute; API / token ;
- tester des endpoints ;
- interpr&eacute;ter les r&eacute;ponses et erreurs.

### 1.2 Travail demand&eacute; (documentation + tests)

1) Lire la page "Getting Started" de la documentation TMDB.
2) Identifier :
- le m&eacute;canisme d'authentification,
- les endpoints utiles (films, recherche, popular, trending, d&eacute;tails),
- les quotas / limitations (si mentionn&eacute;s),
- la structure g&eacute;n&eacute;rale des r&eacute;ponses.

3) Tester au moins 2 appels API depuis :
- un navigateur, ou
- `curl`, ou
- Postman / Insomnia.

Vous devez &ecirc;tre capables d'expliquer :
- comment on authentifie un appel,
- ce qu'est un endpoint,
- ce que renvoie l'API (structure JSON),
- comment on g&egrave;re une erreur (401, 404, 429, etc.).

---

## Partie 2: Int&eacute;gration: adapter votre back-end

### 2.1 Objectif

Adapter votre back-end existant pour qu'il consomme l'API TMDB et expose **votre propre API** au front-end.

Dans le monde r&eacute;el, le front n'appelle pas toujours directement une API externe :
- pour des raisons de s&eacute;curit&eacute; (cl&eacute; API),
- de contr&ocirc;le (format),
- de cache,
- de performance,
- de logique m&eacute;tier.

### 2.2 Travail demand&eacute;

1) Ajouter dans votre back-end une route qui interroge TMDB et renvoie des films au front :
- exemple : `/movies` doit d&eacute;sormais renvoyer une liste issue de TMDB (ou un sous-ensemble).

2) Standardiser la r&eacute;ponse de votre API :
- votre front doit recevoir un format coh&eacute;rent (m&ecirc;me champs, m&ecirc;me structure),
- m&ecirc;me si TMDB renvoie plus d'infos.

3) G&eacute;rer au minimum :
- les erreurs d'authentification (cl&eacute; manquante / invalide),
- les erreurs r&eacute;seau,
- les erreurs de rate-limit (si d&eacute;tect&eacute;es),
- un message d'erreur propre c&ocirc;t&eacute; client.

4) (Optionnel mais recommand&eacute;) Ajouter une couche de cache simple :
- &eacute;viter d'appeler TMDB &agrave; chaque refresh front-end.

---

## Partie 3: Adapter le front-end (catalogue r&eacute;el)
<!-- (â‰ˆ 1h â€“ 1h30) -->

### 3.1 Objectif

Adapter votre front-end pour afficher un catalogue r&eacute;el (issu de TMDB via votre back-end).

### 3.2 Travail demand&eacute;

1) Le front doit afficher :
- titre,
- date (si disponible),
- synopsis/description (si disponible),
- image (poster).
- etc.

2) Le front doit &ecirc;tre robuste :
- afficher un message si aucune donn&eacute;e n'est disponible,
- afficher un message si l'API renvoie une erreur.

3) Ajouter une fonctionnalit&eacute; simple :
- recherche (par titre), ou
- filtre (popular / trending), ou
- pagination / "charger plus".

Le choix est libre : vous devez le justifier.

---

## Partie 4: Collecte de donn&eacute;es : export (scraping / extraction)

### 4.1 Objectif

Mettre en place une collecte de donn&eacute;es &agrave; partir de votre application :
- r&eacute;cup&eacute;rer un grand nombre de films,
- sauvegarder les informations dans un format choisi,
- documenter la m&eacute;thode et ses limites.

Attention : ici on distingue deux choses :
- **Consommer une API** (souvent autoris&eacute; et pr&eacute;vu),
- **Scraper des pages web** (peut &ecirc;tre limit&eacute; / interdit selon les sites).

Dans ce TME, la collecte peut se faire :
- par appels API (recommand&eacute;),
- ou par scraping (si vous justifiez et respectez les r&egrave;gles).

### 4.2 Travail demand&eacute; (export)

1) D&eacute;finir votre strat&eacute;gie de collecte :
- quels films r&eacute;cup&eacute;rer ? (popular, trending, recherche, pages 1..N, etc.)
- combien ? (ex : 200, 500, 1000, ... selon temps et limites)

2) Choisir un format d'export :
- JSON
- CSV
- XML
- YAML
- autre (autoris&eacute;)

3) Impl&eacute;menter un script (ou une route back-end) qui :
- collecte les films,
- sauvegarde le r&eacute;sultat dans un fichier.

4) Sauvegarder aussi (si vous g&eacute;rez les images/posters) :
- soit l'URL uniquement,
- soit les fichiers images localement (optionnel).

---

### 4.3 Partie "web scraping" (documentation + &eacute;thique + l&eacute;galit&eacute;)

Si vous faites du scraping (pages HTML) :
- vous devez vous documenter sur :
  - ce qui est l&eacute;gal ou non,
  - les conditions d'utilisation du site,
  - le respect de `robots.txt`,
  - les bonnes pratiques (limiter la fr&eacute;quence, user-agent, etc.).

M&ecirc;me si vous ne scrapez pas, vous devez comprendre :
- la diff&eacute;rence entre **API officielle** et **scraping**,
- les risques techniques et juridiques.

---

## Partie 5: Bonnes pratiques avanc&eacute;es (API r&eacute;elle)
<!-- (â‰ˆ 30â€“45 min) -->

Vous devez vous documenter sur :
- rate limiting et strat&eacute;gies (retry, backoff),
- cache (local / serveur),
- pagination,
- s&eacute;curit&eacute; (ne pas exposer de secrets c&ocirc;t&eacute; front),
- logs et observabilit&eacute;.

**&Agrave; inclure dans votre rapport** :
- une synth&egrave;se (avec sources),
- ce que vous avez mis en place,
- ce que vous feriez en production.

---

## R&eacute;sultat attendu

&Agrave; la fin du TME 3, vous devez avoir :
- un front-end qui affiche des films issus d'une API r&eacute;elle (via votre back-end),
- un back-end qui int&egrave;gre proprement TMDB,
- un export de donn&eacute;es (format choisi),
- un rapport enrichi avec sources et justification.

---

## Remarque importante

Vous n'&ecirc;tes pas &eacute;valu&eacute;s uniquement sur le code,
mais surtout sur votre capacit&eacute; &agrave; :
- lire une documentation technique,
- choisir une architecture coh&eacute;rente,
- justifier vos d&eacute;cisions,
- produire une d&eacute;marche r&eacute;aliste et argument&eacute;e.

---
---
---

# Annexe: Tutoriel progressif (TME 3)
> **Optionnel mais recommand&eacute; si vous &ecirc;tes bloqu&eacute;s.**  
> Ce tutoriel propose **un chemin guid&eacute; possible** pour r&eacute;aliser les fonctionnalit&eacute;s demand&eacute;es dans le TME 3 (API TMDB + adaptation back/front + export).  
> Vous &ecirc;tes **libres** d'impl&eacute;menter une autre solution tant qu'elle est **fonctionnelle, coh&eacute;rente et justifi&eacute;e** dans le rapport.

---

## 0) Pr&eacute;-requis et rappel de l'objectif

### Objectif final de l'annexe
&Agrave; la fin de ce tutoriel, vous aurez :
- un **back-end FastAPI** qui appelle **TMDB** et expose une route `/movies` (API proxy) ;
- un **front-end HTML/CSS/JS** qui affiche les films **dynamiquement** (sans donn&eacute;es cod&eacute;es en dur) ;
- un **export** de donn&eacute;es (JSON / CSV / XML ... au choix) depuis le back-end.

### Pr&eacute;requis
- Un compte TMDB + une cl&eacute; (API Read Access Token ou API Key selon votre configuration).
- Un environnement Python 3 fonctionnel.
- Votre projet (front + back) du TME 2.

---

## 1) Cr&eacute;er la cl&eacute; TMDB et lire la doc 
<!-- --(5â€“10 min) -->

Documentation officielle : https://developer.themoviedb.org/docs/getting-started

### Ce que vous devez r&eacute;cup&eacute;rer
- Un **token** (souvent "API Read Access Token") ou une **API Key** (selon l'option choisie).
- Comprendre **comment l'authentification marche** (Header `Authorization: Bearer ...` ou `api_key=...`).

---

## 2) Tester TMDB "&agrave; la main" avec `curl` 
<!-- (10 min) -->

L'objectif : v&eacute;rifier que votre cl&eacute; fonctionne **avant** de coder.

### Exemple : r&eacute;cup&eacute;rer des films populaires
> Si vous utilisez un token Bearer (souvent le cas), testez :

```bash
export TMDB_TOKEN="VOTRE_TOKEN_ICI"
curl -s -H "Authorization: Bearer $TMDB_TOKEN" \
  -H "accept: application/json" \
  "https://api.themoviedb.org/3/movie/popular?language=fr-FR&page=1" | head
```

Vous devez voir du JSON.

---

## 3) Back-end: Transformer votre API en "proxy TMDB" (FastAPI)

### 3.1 Arborescence conseill&eacute;e (simple)
```
backend/
|- main.py
|- movies.json              # optionnel (utile pour export local)
|- exports/                 # fichiers export&eacute;s (json/csv/...)
|- .env                     # cl&eacute; TMDB (non commit)
```

Ne commitez jamais votre cl&eacute; API dans Git.

---

### 3.2 Installer les d&eacute;pendances
Dans `backend/` (venv activ&eacute;) :

```bash
pip install fastapi uvicorn python-dotenv requests
```

- `python-dotenv` : lire un fichier `.env`
- `requests` : appeler TMDB (simple)

---

### 3.3 Ajouter un fichier `.env` (cl&eacute; TMDB)
Cr&eacute;er `backend/.env` :

```ini
TMDB_TOKEN=VOTRE_TOKEN_ICI
```

---

### 3.4 Exemple de `main.py` (TMDB --> /movies)

> Ce code :
> - appelle TMDB `/movie/popular`
> - **normalise** les champs pour que le front garde (presque) le m&ecirc;me code que TME2
> - ajoute un param&egrave;tre `limit` comme dans le TME 2

Cr&eacute;ez/Remplacez `backend/main.py` par :

```python
from fastapi import FastAPI, Query
from fastapi.middleware.cors import CORSMiddleware
from dotenv import load_dotenv
import os
import requests
from pathlib import Path
import json
from datetime import datetime
import urllib3
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

load_dotenv()

app = FastAPI()

# Pour simplifier le TME : autorise toutes les origines.
# En "monde r&eacute;el", on restreint &agrave; l'URL exacte du front.
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

TMDB_TOKEN = os.getenv("TMDB_TOKEN", "").strip()
TMDB_BASE = "https://api.themoviedb.org/3"
TMDB_IMG_BASE = "https://image.tmdb.org/t/p/w500"  # posters en taille raisonnable

BASE_DIR = Path(__file__).parent
EXPORT_DIR = BASE_DIR / "exports"
EXPORT_DIR.mkdir(exist_ok=True)

@app.get("/hello")
def hello():
    return {"message": "Hello World"}

def tmdb_get(path: str, params: dict | None = None) -> dict:
    if not TMDB_TOKEN:
        raise RuntimeError("TMDB_TOKEN manquant. Ajoutez-le dans backend/.env")

    url = f"{TMDB_BASE}{path}"
    headers = {
        "Authorization": f"Bearer {TMDB_TOKEN}",
        "accept": "application/json"
    }
    r = requests.get(url, headers=headers, params=params, timeout=15, verify=False)
    r.raise_for_status()
    return r.json()

def normalize_tmdb_movie(m: dict) -> dict:
    """
    Normalisation : on renvoie un format proche du TME2 :
    - title
    - director (pas dispo dans /movie/popular => "N/A")
    - description
    - image_url (ici : URL ABSOLUE)
    """
    poster_path = m.get("poster_path")  # ex: "/abc.jpg"
    image_url = f"{TMDB_IMG_BASE}{poster_path}" if poster_path else ""

    return {
        "title": m.get("title") or m.get("name") or "Sans titre",
        "director": "N/A",  # option: &agrave; am&eacute;liorer en appelant /movie/{id}/credits
        "description": m.get("overview") or "",
        "image_url": image_url,
        "year": (m.get("release_date") or "")[:4],
        "tmdb_id": m.get("id"),
    }

@app.get("/movies")
def get_movies(limit: int | None = Query(default=12, ge=1, le=50)):
    """
    Retourne une liste de films depuis TMDB.
    - limit = nombre de films renvoy&eacute;s (max 50 ici pour rester simple)
    """
    data = tmdb_get("/movie/popular", params={"language": "fr-FR", "page": 1})
    results = data.get("results", [])
    movies = [normalize_tmdb_movie(m) for m in results]

    if limit is not None:
        movies = movies[:limit]

    return movies

@app.get("/export/movies.json")
def export_movies_json(limit: int | None = Query(default=50, ge=1, le=200)):
    """
    Exemple d'export JSON c&ocirc;t&eacute; serveur (vous pouvez proposer CSV/XML aussi).
    """
    data = tmdb_get("/movie/popular", params={"language": "fr-FR", "page": 1})
    results = data.get("results", [])
    movies = [normalize_tmdb_movie(m) for m in results][:limit]

    stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    out = EXPORT_DIR / f"movies_export_{stamp}.json"
    out.write_text(json.dumps(movies, ensure_ascii=False, indent=2), encoding="utf-8")

    return {"exported_file": str(out.name), "count": len(movies)}
```

#### Lancer le back-end
Dans `backend/` :

```bash
uvicorn main:app --reload
```

#### Tester dans le terminal
```bash
curl -s "http://127.0.0.1:8000/movies?limit=5" | head
curl -s "http://127.0.0.1:8000/export/movies.json?limit=20"
```

---

## 4) Front-end: R&eacute;utiliser le m&ecirc;me HTML/CSS/JS (avec un petit ajustement)

L'id&eacute;e : garder votre interface TME2, et remplacer la source "films cod&eacute;s en dur" par l'API `/movies`.

### 4.1 Arborescence front-end (identique TME2)
```
front-end/
|- index.html
|- style.css
|- script.js
```

### 4.2 `index.html` (identique)
```html
<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Catalogue de films</title>
  <link rel="stylesheet" href="style.css" />
</head>
<body>
  <header class="header">
    <h1>Catalogue de films</h1>
    <p>Interface front-end - aliment&eacute;e par le back-end (proxy TMDB)</p>
  </header>

  <main class="container">
    <div id="movies" class="grid"></div>
  </main>

  <script src="script.js"></script>
</body>
</html>
```

### 4.3 `style.css` (identique)
```css
* { box-sizing: border-box; }

body {
  margin: 0;
  font-family: Arial, sans-serif;
  background: #f5f5f5;
  color: #222;
}

.header {
  padding: 24px 16px;
  background: white;
  border-bottom: 1px solid #ddd;
}

.container {
  padding: 16px;
}

.grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(260px, 1fr));
  gap: 16px;
}

.card {
  background: white;
  border-radius: 10px;
  overflow: hidden;
  border: 1px solid #e5e5e5;
}

.card img {
  width: 100%;
  height: 360px;
  object-fit: cover;
  display: block;
}

.card-content {
  padding: 12px 14px;
}

.card h2 {
  margin: 0 0 8px 0;
  font-size: 18px;
}

.meta {
  margin: 0 0 10px 0;
  color: #555;
  font-size: 14px;
}

.desc {
  margin: 0;
  color: #333;
  font-size: 14px;
  line-height: 1.4;
}
```

### 4.4 `script.js`

> Important : dans le back-end de ce tutoriel, `image_url` est une **URL absolue** (ex: `https://image.tmdb.org/...`)  
> Donc on doit **&eacute;viter** de pr&eacute;fixer par `http://127.0.0.1:8000` si l'URL est d&eacute;j&agrave; compl&egrave;te.

Cr&eacute;ez/Remplacez `front-end/script.js` par :

```js
const API_BASE = "http://127.0.0.1:8000";
const container = document.getElementById("movies");

/** R&eacute;cup&eacute;rer les films depuis le back-end */
async function loadMovies(limit = 12) {
  const res = await fetch(`${API_BASE}/movies?limit=${limit}`);
  if (!res.ok) {
    throw new Error(`Erreur API: ${res.status} ${res.statusText}`);
  }
  return await res.json();
}

function resolveImageUrl(movie) {
  // Si l'API renvoie une URL absolue (TMDB), on l'utilise telle quelle.
  // Sinon, on pr&eacute;fixe par l'API (cas TME2: "/images/xxx.jpg").
  const u = movie.image_url || "";
  if (u.startsWith("http://") || u.startsWith("https://")) return u;
  return `${API_BASE}${u}`;
}

function renderMovies(movies) {
  container.innerHTML = "";

  movies.forEach(movie => {
    const card = document.createElement("article");
    card.className = "card";

    const img = resolveImageUrl(movie);

    card.innerHTML = `
      <img src="${img}" alt="${movie.title}">
      <div class="card-content">
        <h2>${movie.title}</h2>
        <p class="meta"><strong>R&eacute;alisateur :</strong> ${movie.director ?? "N/A"}</p>
        <p class="desc">${movie.description ?? ""}</p>
      </div>
    `;

    container.appendChild(card);
  });
}

async function main() {
  try {
    const movies = await loadMovies(12);
    renderMovies(movies);
  } catch (err) {
    console.error(err);
    container.innerHTML = `<p>Erreur: ${err.message}</p>`;
  }
}

main();
```

---

## 5) Export: Aller plus loin (CSV / XML) (optionnel mais valoris&eacute;)

Dans le tutoriel on a montr&eacute; un export JSON.

### Id&eacute;es simples &agrave; r&eacute;aliser
- Export CSV : `title;year;tmdb_id`
- Export XML : structurer les films dans des balises

---

## 6) "Scraping": Cadre l&eacute;gal et bonnes pratiques (&agrave; traiter dans le rapport)

### &Agrave; comprendre
- **API** = voie officielle (conditions d'utilisation d&eacute;finies)
- **Scraping** = extraction depuis des pages HTML (souvent interdit ou limit&eacute;)
- `robots.txt` donne des indications, mais ne remplace pas les CGU.
---

## 7) D&eacute;bogage rapide (probl&egrave;mes fr&eacute;quents)

### 7.1 Erreur CORS
- V&eacute;rifiez que le middleware CORS est activ&eacute; c&ocirc;t&eacute; back.
- V&eacute;rifiez que vous appelez le bon port.

### 7.2 401 Unauthorized
- Token absent ou invalide.
- V&eacute;rifiez `backend/.env` et le chargement `load_dotenv()`.

### 7.3 Images non visibles
- `poster_path` peut &ecirc;tre `null` --> image_url vide.
- Le front doit tol&eacute;rer une image manquante.

---

## 8) Checklist finale (ce que vous devez avoir)

- `/movies?limit=5` renvoie 5 films depuis TMDB (via le back-end)
- Le front affiche des cartes (titre + description + image)
- L'export JSON fonctionne et produit un fichier dans `backend/exports/`

---

## Bonus (si vous voulez aller plus loin)
- Ajouter une route `/movies/search?query=...`
- Ajouter de la pagination (`page`, `limit`)
- Ajouter un cache (Redis) c&ocirc;t&eacute; back-end
- Stocker en base (PostgreSQL / MongoDB)
