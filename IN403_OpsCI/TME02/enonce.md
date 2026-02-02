# TME 2: Conception et mise en place d'une application Web (Front-end & Back-end)

## Objectif p&eacute;dagogique

L'objectif de ce TME est d'apprendre &agrave; **concevoir, justifier et impl&eacute;menter** une application web simple,
en suivant une d&eacute;marche **r&eacute;aliste et proche du monde professionnel**.

&Agrave; la fin de ce TME, vous devez avoir :
- une **architecture claire**, pens&eacute;e avant le code ;
- un **back-end simple exposant une API** ;
- un **front-end simple** ;
- une **communication fonctionnelle entre le front-end et le back-end**.

**Aucun livrable n'est demand&eacute; &agrave; la fin de ce TME.**  
En revanche, vous devez **commencer &agrave; r&eacute;diger le rapport de votre projet d&egrave;s maintenant**.  
Ce rapport sera enrichi et compl&eacute;t&eacute; tout au long des prochains TME.

---

<!-- ## Organisation g&eacute;n&eacute;rale

- Travail **individuel ou en bin&ocirc;me**
- Dur&eacute;e : **4h &agrave; 5h**
- Technologies : **libres**, tant qu'elles sont coh&eacute;rentes et justifi&eacute;es
- Le rapport doit &ecirc;tre **r&eacute;dig&eacute; au fur et &agrave; mesure**, pas apr&egrave;s coup

--- -->

## Partie 1: Architecture & conception 
<!-- (â‰ˆ 1h) -->

### 1.1 Pourquoi commencer par l'architecture ?

Toute application s&eacute;rieuse commence par une phase de r&eacute;flexion :
- comment les diff&eacute;rentes parties communiquent ;
- comment les responsabilit&eacute;s sont s&eacute;par&eacute;es ;
- comment l'application pourra &eacute;voluer.

Cette &eacute;tape est **obligatoire** et pr&eacute;c&egrave;de toute impl&eacute;mentation.

---

### 1.2 Introduction aux design patterns

Un **design pattern** est une solution g&eacute;n&eacute;rique &agrave; un probl&egrave;me r&eacute;current de conception logicielle.

Exemples courants :
- MVC (Model -- View -- Controller)
- Architecture client--serveur
- Architecture en couches (layered architecture)
- Repository pattern

Il ne s'agit pas d'appliquer des patterns de mani&egrave;re m&eacute;canique.  
Un ou deux patterns bien choisis sont largement suffisants.

---

### 1.3 Travail demand&eacute;

1. D&eacute;finir l'**architecture globale** de votre application :
   - front-end,
   - back-end,
   - donn&eacute;es.

2. R&eacute;aliser un **sch&eacute;ma simple** d'architecture  
   (papier, draw.io, excalidraw, etc.).

3. Choisir **un ou deux design patterns maximum**.

---

### 1.4 &Agrave; r&eacute;diger dans le rapport (d&egrave;s maintenant)

Votre rapport doit montrer une **d&eacute;marche de conception**, et pas uniquement un r&eacute;sultat final.

Vous devez donc distinguer clairement :
1. ce que vous avez **&eacute;tudi&eacute;** ;
2. ce que vous avez **choisi** ;
3. comment vous avez **con&ccedil;u votre application**.

---

#### &Eacute;tude des architectures existantes

Avant de pr&eacute;senter votre propre architecture, vous devez :
- identifier **plusieurs architectures couramment utilis&eacute;es** en d&eacute;veloppement logiciel ;
- expliquer bri&egrave;vement dans quels contextes elles sont utilis&eacute;es.

Exemples possibles (liste non exhaustive) :
- architecture monolithique,
- architecture client--serveur,
- architecture en couches (layered),
- architecture microservices,

**&Agrave; inclure dans votre rapport** :
- une description synth&eacute;tique de plusieurs architectures [2, inf];
- leurs avantages et limites ;
- des exemples de cas d'usage.

---

#### &Eacute;tude des design patterns

De la m&ecirc;me mani&egrave;re, vous devez &eacute;tudier **plusieurs design patterns courants**.

Exemples possibles :
- MVC,
- Repository,
- Singleton,
- Factory,
- Observer.

**&Agrave; inclure dans votre rapport** :
- une pr&eacute;sentation de plusieurs design patterns [2, inf];
- le probl&egrave;me que chaque pattern cherche &agrave; r&eacute;soudre ;
- leurs avantages et leurs limites.

---

#### Choix et justification

Apr&egrave;s cette phase d'&eacute;tude, vous devez :
- indiquer **quelle architecture** vous avez retenue ;
- indiquer **quel(s) design pattern(s)** vous avez choisi(s).

**&Agrave; inclure dans votre rapport** :
- les raisons de vos choix ;
- pourquoi ces choix sont adapt&eacute;s &agrave; votre projet ;
- pourquoi vous n'avez pas retenu certaines autres options.

---

#### Conception de votre application

Enfin, vous devez pr&eacute;senter **votre conception finale**.

**&Agrave; inclure dans votre rapport** :
- un sch&eacute;ma clair de votre architecture ;
- l'organisation globale de votre application ;
- le r&ocirc;le de chaque composant (front-end, back-end, donn&eacute;es).

---

L'objectif n'est pas d'avoir *la meilleure architecture possible*,  
mais de montrer que vos choix sont **r&eacute;fl&eacute;chis, coh&eacute;rents et justifi&eacute;s**.


---
## Partie 2: Back-end & API
<!-- (â‰ˆ 1h30 -- 2h) -->

### 2.1 Objectif

Mettre en place un **back-end minimal** exposant une **API HTTP** :
- une route simple `/hello` ;
- une route `/movies` qui retourne des donn&eacute;es depuis un fichier **JSON**.

> Avant de coder, un ing&eacute;nieur choisit une **stack** (au minimum : un langage + un framework).
> Cette &eacute;tape fait partie du travail attendu et doit appara&icirc;tre dans votre rapport.

---

### 2.2 &Eacute;tape 0: Choisir la stack back-end (recherche + justification)

#### 2.2.1 Travail demand&eacute; (recherche guid&eacute;e)

1. Choisir **3 langages back-end** (exemples possibles : Python, Java, JavaScript/Node.js, Go, C#, PHP, Ruby).
2. Faire une **mini-&eacute;tude**:
   - Dans quels contextes chaque langage est-il souvent utilis&eacute; ?
   - Pour quels types d'applications est-il adapt&eacute; ? (API, web, data, syst&egrave;mes, temps r&eacute;el, etc.)
   - Quels sont ses points forts/faibles ?

#### 2.2.2 KPI : notion "entreprise"

En entreprise, un **KPI** (*Key Performance Indicator*) est un **indicateur** pour comparer des options et prendre une d&eacute;cision.
Ici, vous devez choisir des **KPI pertinents** pour comparer des langages back-end.

Exemples de KPI possibles (vous n'&ecirc;tes pas oblig&eacute;s de tous les prendre) :
- **Courbe d'apprentissage** (facile/moyen/difficile)
- **&Eacute;cosyst&egrave;me** (nombre de libs, frameworks, outils)
- **Performance** (temps d'ex&eacute;cution, latence)
- **Productivit&eacute;** (rapidit&eacute; &agrave; d&eacute;velopper)
- **March&eacute; de l'emploi** (pr&eacute;sence en entreprise, offres)
- **Communaut&eacute;** (docs, forums, support)
- **D&eacute;ploiement** (simplicit&eacute;, portabilit&eacute;)
- **Cas d'usage typiques** (API, data, microservices, etc.)


---

### 2.3 &Eacute;tape 1 -- Impl&eacute;mentation : API minimale (Hello World)

Une fois le langage choisi, vous impl&eacute;mentez l'API.

Pour vous aider et homog&eacute;n&eacute;iser la s&eacute;ance, nous vous guidons avec **Python 3** (exemple de r&eacute;f&eacute;rence).
> Si vous choisissez un autre langage, c'est autoris&eacute;, mais vous devez &ecirc;tre autonomes.

---

### 2.3.1 Environnement virtuel Python (recherche + mise en pratique)

#### Travail demand&eacute;
Avant d'installer des librairies, vous devez comprendre et utiliser un **environnement virtuel**.

1. Chercher et expliquer dans votre rapport :
   - c'est quoi un **environnement virtuel** (venv) ?
   - pourquoi on l'utilise ?
   - quel probl&egrave;me il r&eacute;sout en entreprise ?

#### Commandes (Python 3)

Dans un dossier de projet (ex : `backend/`) :

```bash
python -m venv venv
source venv/bin/activate
python -m pip install --upgrade pip
```

---

### 2.3.2 Installation du framework API

Installer un framework API simple (**FastAPI**) et un serveur ASGI (**Uvicorn**) :

```bash
pip install fastapi uvicorn
```

---

### 2.3.3 Cr&eacute;ation de la route `GET /hello`

Cr&eacute;er un fichier `main.py` :

```python
from fastapi import FastAPI

app = FastAPI()

@app.get("/hello")
def hello():
    return {"message": "Hello World"}
```

Lancer le serveur :

```bash
uvicorn main:app --reload
```

Tester :
- Navigateur : `http://127.0.0.1:8000/hello`
- Ou terminal :

```bash
curl -x "" http://127.0.0.1:8000/hello
```

R&eacute;sultat attendu :

```json
{ "message": "Hello World" }
```

---

### 2.4 &Eacute;tape 2: API avec donn&eacute;es (JSON)

#### Objectif

Cr&eacute;er une route :

```
GET /movies
```

qui lit un fichier **JSON** et retourne son contenu.

---

### 2.4.1 Donn&eacute;es fournies

Un fichier `movies.json` est fourni et contient une liste de films.

Exemple de structure :

```json
[
  {
    "title": "Inception",
    "year": 2010,
    "director": "Christopher Nolan",
    "genre": "Sci-Fi"
  }
]
```

Ce fichier joue le r&ocirc;le d'une **base de donn&eacute;es simplifi&eacute;e**.

---

### 2.4.2 Travail demand&eacute; (recherche + explication)

Dans votre rapport, expliquer :
- ce qu'est le format **JSON** ;
- pourquoi JSON est largement utilis&eacute; dans les API web ;
- citer au moins **deux autres formats de donn&eacute;es** (CSV, XML, YAML, etc.) et donner un cas d'usage.

---

### 2.4.3 Impl&eacute;mentation avec Python (exemple guid&eacute;)

Placer le fichier `movies.json` dans le m&ecirc;me dossier que `main.py`, puis compl&eacute;ter le code :

```python
from fastapi import FastAPI
import json
from pathlib import Path

app = FastAPI()

DATA_PATH = Path(__file__).parent / "movies.json"

@app.get("/hello")
def hello():
    return {"message": "Hello World"}

@app.get("/movies")
def get_movies():
    with open(DATA_PATH, "r", encoding="utf-8") as f:
        movies = json.load(f)
    return movies
```

Relancer le serveur et tester :
- Navigateur : `http://127.0.0.1:8000/movies`
- Ou terminal :

```bash
curl -x "" http://127.0.0.1:8000/movies
```

Vous devez obtenir une **liste JSON de films**.

---
### 2.4.4 Nouvelle route avec param&egrave;tre (limiter le nombre de films)

#### Objectif

Faire &eacute;voluer l'API afin qu'elle puisse retourner **un nombre limit&eacute; de films** en fonction
d'un param&egrave;tre fourni dans la requ&ecirc;te.

L'id&eacute;e est de permettre &agrave; un client de demander :
- seulement **N films** au lieu de toute la liste.

---

#### Comportement attendu

Vous devez impl&eacute;menter une nouvelle route permettant le comportement suivant :

- si le client demande **10**, l'API retourne **les 10 premiers films** ;
- si le client demande **5**, l'API retourne **les 5 premiers films** ;
- si le client demande un nombre sup&eacute;rieur au nombre total de films,
  l'API retourne simplement **tous les films disponibles**.

Le choix pr&eacute;cis de la route (URL, param&egrave;tre de chemin ou param&egrave;tre de requ&ecirc;te)
vous est **laiss&eacute; libre**.

---

#### Exemples d'appels (&agrave; tester dans le terminal)

Les appels suivants doivent fonctionner une fois votre impl&eacute;mentation termin&eacute;e
(la forme exacte de l'URL d&eacute;pend de vos choix) :

```bash
curl -x "" http://127.0.0.1:8000/movies/10
```
ou
```bash
curl -x "" "http://127.0.0.1:8000/movies?limit=10"
curl -x "" "http://127.0.0.1:8000/movies?limit=5"
```

### Travail demand&eacute;

- R&eacute;fl&eacute;chir &agrave; la meilleure fa&ccedil;on de passer un param&egrave;tre &agrave; une API HTTP.
- Impl&eacute;menter la route correspondante.
- V&eacute;rifier le comportement avec plusieurs valeurs (petites, grandes, limites).

### 2.5 &Agrave; r&eacute;diger dans le rapport du projet

- le tableau comparatif des langages et KPI ;
- le langage et le framework choisis avec justification ;
- une explication claire de ce qu'est une **API** (HTTP, endpoints, formats de r&eacute;ponse) ;
- une explication de l'**environnement virtuel** ;
- une explication du format **JSON** et d'autres formats de donn&eacute;es ;

----

## Partie 3: Front-end
<!-- (â‰ˆ 1h) -->

### 3.1 Objectif

L'objectif de cette partie est de concevoir un **front-end fonctionnel**, capable :
- d'afficher une liste de films de mani&egrave;re claire ;
- d'&ecirc;tre **pr&ecirc;t &agrave; &ecirc;tre reli&eacute; &agrave; un back-end** dans la suite du projet.

&Agrave; ce stade, le front-end peut fonctionner de mani&egrave;re **autonome**
(donn&eacute;es cod&eacute;es en dur ou lues depuis un fichier local).

---

### 3.2 &Eacute;tape 0: Choisir la stack front-end (recherche + justification)

Avant de coder, vous devez choisir une **stack front-end**
(langage et/ou framework).

Vous devez comparer **au moins deux options** parmi :
- HTML / CSS / JavaScript
- React
- Vue
- autre (autoris&eacute;)

#### &Eacute;tude demand&eacute;e

Pour chaque option &eacute;tudi&eacute;e, analyser :
- les cas d'usage typiques ;
- le niveau de complexit&eacute; ;
- la performance ;
- la maintenabilit&eacute; ;
- l'utilisation en entreprise.

Comme pour le back-end, vous devez d&eacute;finir des **KPI pertinents**.

Exemples de KPI possibles :
- facilit&eacute; de prise en main ;
- productivit&eacute; ;
- performance ;
- popularit&eacute; / adoption en entreprise ;
- &eacute;cosyst&egrave;me ;
- maintenabilit&eacute; ;
- compatibilit&eacute; avec une API back-end.

**&Agrave; inclure dans votre rapport** :
- un tableau comparatif (technologies x KPI),
- la stack retenue,
- une justification argument&eacute;e du choix.

---

### 3.3 Mettre en place un projet front-end minimal (sans framework)

Dans cette &eacute;tape, vous allez cr&eacute;er un petit projet front-end **sans framework** avec 3 fichiers :
- `index.html` (structure)
- `style.css` (style)
- `script.js` (dynamique)

#### Arborescence attendue

Cr&eacute;ez un dossier `front-end/` avec l'arborescence suivante :

```
front-end/
|-- index.html
|-- style.css
|-- script.js
|-- images/
```

Ensuite :
- T&eacute;l&eacute;chargez **au moins 5 images** de couvertures de films (ou images illustratives),
- Placez-les dans `front-end/images/`.

Vous devez ensuite **mettre &agrave; jour les noms de fichiers** dans le code (voir `script.js`).

**&Agrave; inclure dans votre rapport** :
- votre choix (ou non) d'utiliser un framework,
- une capture de l'interface obtenue,
- les difficult&eacute;s rencontr&eacute;es.

---

### 3.4 Code &agrave; utiliser (HTML / CSS / JS)

#### 3.4.1 Contenu de `index.html`

Cr&eacute;ez `front-end/index.html` et collez :

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
    <p>Interface front-end (donn&eacute;es locales) -- pr&ecirc;te &agrave; &ecirc;tre reli&eacute;e au back-end</p>
  </header>

  <main class="container">
    <div id="movies" class="grid"></div>
  </main>

  <script src="script.js"></script>
</body>
</html>
```

---

#### 3.4.2 Contenu de `style.css`

Cr&eacute;ez `front-end/style.css` et collez :

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

---

#### 3.4.3 Contenu de `script.js`

Cr&eacute;ez `front-end/script.js` et collez :

```js
/**
 * Donn&eacute;es "cod&eacute;es en dur" (locales) pour tester l'affichage.
 * IMPORTANT :
 * - Remplacez les champs "image" par les vrais noms de fichiers plac&eacute;s dans /images
 * - Exemple : images/inception.jpg
 */
const movies = [
  {
    title: "Inception",
    director: "Christopher Nolan",
    description: "Un thriller de science-fiction sur les r&ecirc;ves et la manipulation de l'esprit.",
    image: "images/inception.jpg"
  },
  {
    title: "Interstellar",
    director: "Christopher Nolan",
    description: "Un voyage spatial pour sauver l'humanit&eacute; face &agrave; une Terre en crise.",
    image: "images/interstellar.jpg"
  },
  {
    title: "The Matrix",
    director: "Lana Wachowski, Lilly Wachowski",
    description: "Un hacker d&eacute;couvre la v&eacute;rit&eacute; sur la r&eacute;alit&eacute; et rejoint une r&eacute;bellion.",
    image: "images/matrix.jpg"
  },
  {
    title: "Parasite",
    director: "Bong Joon-ho",
    description: "Une satire sociale o&ugrave; une famille s'infiltre progressivement chez une autre.",
    image: "images/parasite.jpg"
  },
  {
    title: "Spirited Away",
    director: "Hayao Miyazaki",
    description: "Une aventure fantastique dans un monde d'esprits o&ugrave; une jeune fille cherche &agrave; sauver ses parents.",
    image: "images/spiritedaway.jpg"
  }
];

const container = document.getElementById("movies");

/**
 * G&eacute;n&egrave;re les cartes de films dans la page.
 */
movies.forEach(movie => {
  const card = document.createElement("article");
  card.className = "card";
  card.innerHTML = `
    <img src="${movie.image}" alt="${movie.title}">
    <div class="card-content">
      <h2>${movie.title}</h2>
      <p class="meta"><strong>R&eacute;alisateur :</strong> ${movie.director}</p>
      <p class="desc">${movie.description}</p>
    </div>
  `;
  container.appendChild(card);
});
```

Les films sont **cod&eacute;s en dur** dans la variable `movies` en haut du fichier `script.js`.
Vous pouvez :
- garder ce mode "local" pour le moment,
- ou charger les films depuis un fichier `movies.json` local (optionnel).

---

### 3.5 Tester votre front-end

1. Ouvrir `front-end/index.html` dans un navigateur (double-clic).
2. V&eacute;rifier que :
   - les 5 films s'affichent,
   - les images se chargent,
   - le style est correct.

Si les images ne s'affichent pas, v&eacute;rifiez :
- le dossier `images/`,
- les noms de fichiers,
- les chemins dans `script.js` (`images/nom.jpg`).

---

### 3.6 Travail attendu

&Agrave; la fin de cette partie, vous devez disposer :
- d'une interface graphique fonctionnelle ;
- d'une liste de films correctement affich&eacute;e ;
- d'un code clair et structur&eacute;.

---

Cette interface servira de **base** pour la suite du projet,
o&ugrave; le front-end sera reli&eacute; au back-end pour r&eacute;cup&eacute;rer les films via une API.

---

## Partie 4: Communication front-end / back-end
<!-- (â‰ˆ 1h - 1h30) -->

### 4.1 Objectif

Relier le **front-end** au **back-end** via l'API afin que :
- le front r&eacute;cup&egrave;re les films depuis le back-end (et non plus en donn&eacute;es cod&eacute;es en dur) ;
- l'affichage soit construit **dynamiquement** &agrave; partir de la r&eacute;ponse JSON.

L'objectif est de se rapprocher d'un fonctionnement **r&eacute;el** :
> le front est un client, le back est une API, et les donn&eacute;es proviennent du serveur.

---

### 4.2 Pr&eacute;-requis

Vous devez avoir :
- un back-end d&eacute;marr&eacute; (FastAPI) avec une route `/movies` (et id&eacute;alement une option de limitation `limit`) ;
- un front-end fonctionnel (version HTML/CSS/JS **ou** version React).

---

### 4.3 Mise &agrave; jour du back-end (c&ocirc;t&eacute; serveur)

#### 4.3.1 Ajouter une limitation du nombre de films (monde r&eacute;el)

Dans une application r&eacute;elle, il est rare d'envoyer **toute** une liste de donn&eacute;es.
On pr&eacute;f&egrave;re souvent :
- paginer,
- limiter,
- filtrer.

Vous devez permettre au client de demander **N films**.

- Si le client demande 10 --> retourner 10 films
- Si le client demande 5 --> retourner 5 films
- Si le client demande plus que disponible --> retourner tout ce qui existe

Le choix de la forme est libre :
- param&egrave;tre de requ&ecirc;te : `/movies?limit=10`
- ou param&egrave;tre de chemin : `/movies/10`

&Agrave; vous d'impl&eacute;menter la solution c&ocirc;t&eacute; back-end.

**Exemples d'appels terminal (&agrave; adapter &agrave; votre choix) :**
```bash
curl -x "" "http://127.0.0.1:8000/movies?limit=10"
curl -x "" "http://127.0.0.1:8000/movies?limit=5"
```

---

#### 4.3.2 Autoriser l'acc&egrave;s depuis le front (CORS)

Quand le front (ex : `http://localhost:5173`) appelle le back (ex : `http://127.0.0.1:8000`),
le navigateur peut bloquer l'appel &agrave; cause de **CORS**.

Vous devez :
- comprendre ce qu'est CORS ;
- configurer le back-end pour autoriser votre front &agrave; appeler l'API.

Indication FastAPI (exemple) : activer CORS middleware pour votre origine front.
> Vous devez adapter l'origine &agrave; votre configuration (port / domaine).

**&Agrave; inclure dans votre rapport** :
- ce qu'est CORS,
- pourquoi &ccedil;a bloque,
- comment vous avez r&eacute;solu le probl&egrave;me (configuration serveur).

---

### 4.4 Mise &agrave; jour du front-end (c&ocirc;t&eacute; client)

L'objectif : remplacer les films cod&eacute;s en dur par un appel &agrave; l'API.

#### 4.4.1 Version HTML / CSS / JS (sans framework)

Dans `script.js`, vous aviez une variable `movies = [...]` en dur.

Vous devez :
1. Supprimer (ou ignorer) les donn&eacute;es cod&eacute;es en dur.
2. Faire un appel HTTP vers l'API.
3. Utiliser la r&eacute;ponse JSON pour construire l'affichage.

**Indication (exemple minimal avec `fetch`) :**
```js
async function loadMovies(limit = 5) {
  const res = await fetch(`http://127.0.0.1:8000/movies?limit=${limit}`);
  const movies = await res.json();
  return movies;
}
```

Puis g&eacute;n&eacute;rer l'affichage comme avant &agrave; partir de `movies`.

Attention : vos objets re&ccedil;us du back-end peuvent contenir des champs diff&eacute;rents.
Vous devez adapter votre code front-end au format renvoy&eacute;.

---

#### 4.4.2 Servir des images depuis le back-end

Dans une application, les images ne sont pas stock&eacute;es c&ocirc;t&eacute; front-end par d&eacute;faut :
- elles peuvent &ecirc;tre stock&eacute;es sur le serveur,
- ou sur un service externe (CDN, S3, etc.),
- et le front r&eacute;cup&egrave;re **une URL** pour les afficher.

Objectif : faire en sorte que le back-end fournisse une **URL d'image** pour chaque film,
et que le front affiche ces images.

##### &Eacute;tape A -- Ajouter un dossier d'images c&ocirc;t&eacute; back-end

Dans votre projet back-end, cr&eacute;ez un dossier :

```
backend/
|-- images/
```

Ajoutez au moins 5 images dedans (affiches ou images illustratives), par exemple :

```
backend/images/inception.jpg
backend/images/interstellar.jpg
...
```

##### &Eacute;tape B -- Modifier les donn&eacute;es (movies.json)

Dans `movies.json`, ajoutez un champ `image_url` (ou un autre nom coh&eacute;rent) pour chaque film.
Exemple :

```json
{
  "title": "Inception",
  "year": 2010,
  "director": "Christopher Nolan",
  "genre": "Sci-Fi",
  "image_url": "/images/inception.jpg"
}
```

Ici l'URL commence par `/images/...` car le back-end servira ces fichiers comme des ressources statiques.

##### &Eacute;tape C -- Servir des fichiers statiques avec FastAPI

Vous devez configurer le back-end pour servir le dossier `images/` comme des fichiers statiques.
L'objectif : quand le navigateur demande :

```
http://127.0.0.1:8000/images/inception.jpg
```

le back-end renvoie effectivement l'image.

Indication (FastAPI) : utilisez le m&eacute;canisme de **static files** pour monter un dossier.

##### &Eacute;tape D -- Adapter le front-end pour afficher l'image

Quand le front re&ccedil;oit un film avec :

```json
"image_url": "/images/inception.jpg"
```

alors l'URL compl&egrave;te &agrave; utiliser c&ocirc;t&eacute; front sera :

```
http://127.0.0.1:8000/images/inception.jpg
```

Vous devez donc :
1. lire le champ `image_url`,
2. construire une URL compl&egrave;te (base API + chemin),
3. l'utiliser dans la balise `<img>`.

Exemple (principe) :

```js
const API_BASE = "http://127.0.0.1:8000";

const imageSrc = API_BASE + movie.image_url; // ex: http://127.0.0.1:8000/images/inception.jpg
```
___

### 4.5 O&ugrave; traiter les donn&eacute;es ?

Dans une vraie application, il faut d&eacute;cider :
- Qu'est-ce qu'on traite c&ocirc;t&eacute; **client** ?
- Qu'est-ce qu'on traite c&ocirc;t&eacute; **serveur** ?

Exemples :
- filtrage (genre) : client ? serveur ?
- pagination : client ? serveur ?
- validation / s&eacute;curit&eacute; : client ? serveur ?

Travail demand&eacute; :
- Vous devez vous documenter (sources) sur les bonnes pratiques.
- Vous devez &ecirc;tre capables d'expliquer **o&ugrave;** il est pr&eacute;f&eacute;rable de faire certains traitements, et pourquoi.

---

### 4.6 Bonnes pratiques API : bonne API vs mauvaise API

Vous devez rechercher des "best practices" de conception d'API, par exemple :
- conventions de routes (noms, pluriels, ressources),
- codes HTTP (200/400/404/500),
- coh&eacute;rence des formats de r&eacute;ponse,
- validation d'entr&eacute;es,
- gestion des erreurs (messages clairs),
- versioning (v1/v2),
- pagination / limitation,
- s&eacute;curit&eacute; (ne pas exposer des infos sensibles),
- documentation (OpenAPI / Swagger).

Travail demand&eacute; :
- Lire au moins 2 sources cr&eacute;dibles (doc officielle, articles techniques reconnus).
- R&eacute;diger une synth&egrave;se : ce qui distingue une bonne API d'une mauvaise API.
- Donner 2--3 exemples concrets appliqu&eacute;s &agrave; **votre** API.

**&Agrave; inclure dans votre rapport** :
- vos sources,
- votre synth&egrave;se (bonne vs mauvaise API),
- ce que vous avez appliqu&eacute; (ou ce que vous feriez ensuite),
- les difficult&eacute;s rencontr&eacute;es (CORS, formats, erreurs, etc.).

---

### 4.7 R&eacute;sultat attendu

&Agrave; la fin de cette partie :
- le front n'utilise plus des films cod&eacute;s en dur comme source principale ;
- le front affiche une liste de films obtenue depuis l'API ;
- vous savez expliquer les probl&egrave;mes rencontr&eacute;s (CORS, format JSON, etc.) ;
- vous avez commenc&eacute; &agrave; formaliser des bonnes pratiques API.

---

### Note

Vous n'&ecirc;tes pas &eacute;valu&eacute;s uniquement sur le r&eacute;sultat final,
mais sur votre capacit&eacute; &agrave; :
- r&eacute;fl&eacute;chir,
- justifier vos choix,
- documenter correctement votre travail (rapport + sources).
