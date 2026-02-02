#!/bin/bash
# Mini-lab : démarrer/tester/arrêter un serveur HTTP
# Automatisation de l'exercice B3

PORT=8080
DIR="../workspace_backup"

echo "Mini-lab serveur HTTP (port $PORT)"
echo "======================================"

# ===== 1. Démarrer le serveur =====
echo ""
echo "[1/5] Demarrage du serveur HTTP..."
python3 -m http.server $PORT --directory $DIR &
SERVER_PID=$!
echo "   PID du serveur : $SERVER_PID"
sleep 1  # Laisser le temps au serveur de démarrer

# ===== 2. Vérifier qu'il écoute =====
echo ""
echo "[2/5] Verification que le port $PORT est en ecoute..."
if ss -lntp 2>/dev/null | grep -q ":$PORT"; then
    echo "   [OK] Port $PORT : OUVERT"
    ss -lntp 2>/dev/null | grep ":$PORT"
else
    echo "   [ERREUR] Port $PORT non ouvert!"
    exit 1
fi

# ===== 3. Tester avec curl =====
echo ""
echo "[3/5] Test HTTP avec curl..."
RESPONSE=$(curl -s -o /dev/null -w "%{http_code}" http://localhost:$PORT 2>&1)
if [ "$RESPONSE" = "200" ]; then
    echo "   [OK] Reponse HTTP : $RESPONSE OK"
    echo ""
    echo "   Apercu de la page:"
    curl -s http://localhost:$PORT | head -8
else
    echo "   [ERREUR] Erreur HTTP : $RESPONSE"
fi

# ===== 4. Arrêter le serveur =====
echo ""
echo "[4/5] Arret du serveur (PID $SERVER_PID)..."
kill $SERVER_PID 2>/dev/null
wait $SERVER_PID 2>/dev/null
echo "   [OK] Serveur arrete"

# ===== 5. Vérifier fermeture =====
echo ""
echo "[5/5] Verification que le port $PORT est ferme..."
sleep 1
if ss -lntp 2>/dev/null | grep -q ":$PORT"; then
    echo "   [WARN] Port encore ouvert!"
else
    echo "   [OK] Port $PORT : FERME"
fi

# Test final avec curl (doit échouer)
echo ""
echo "Test final (doit echouer)..."
if curl -s --connect-timeout 1 http://localhost:$PORT 2>&1 | grep -q "Failed to connect"; then
    echo "   [OK] Connexion refusee (attendu)"
else
    echo "   [WARN] Connexion inattendue"
fi

echo ""
echo "Mini-lab termine avec succes!"
