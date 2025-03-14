const express = require('express');
const app = express();
const port = 8000;

// Middleware pour servir les fichiers statiques
app.use(express.static(__dirname + '/public'));

// Créer un routeur
const router = express.Router();

// Route pour la page d'accueil
router.get('/', (req, res) => {
  res.set('Content-Type', 'text/plain; charset=utf-8');
  res.send('Tout va à merveille');
});

// Route pour /test1
router.get('/test1', (req, res) => {
  res.set('Content-Type', 'text/plain; charset=utf-8');
  res.send('Tout va à merveille pour cette page 1');
});

// Route pour /essailmao
router.get('/essai:lmao', (req, res) => {
  res.set('Content-Type', 'text/plain; charset=utf-8');
  res.send(`Tout va à merveille pour cette page ${req.params.lmao}`);
});

// Utiliser le routeur
app.use('/', router);

// Middleware pour gérer les erreurs 404
app.use((req, res, next) => {
  res.status(404).set('Content-Type', 'text/plain; charset=utf-8');
  res.send("Cette page n’existe pas");
});

app.listen(port, () => {
  console.log('Tout va à merveille');
});
