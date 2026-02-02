#!/bin/bash
# Script de collecte d'informations système
# Génère des rapports dans system-report/

# Créer le dossier system-report s'il n'existe pas
mkdir -p ../system-report

echo "Collecte des informations système..."

# ===== 1. Matériel (CPU, RAM, Disque) =====
echo "[1/3] Collecte hardware..."
{
    echo "=== INFORMATIONS MATÉRIEL ==="
    echo "Date: $(date)"
    echo ""
    
    echo "--- CPU ---"
    lscpu | grep -E "Model name|Architecture|CPU\(s\)|Thread"
    echo ""
    
    echo "--- RAM ---"
    free -h
    echo ""
    
    echo "--- DISQUE ---"
    df -h
    echo ""
    
    echo "--- SYSTÈME ---"
    uname -a
    cat /etc/os-release | head -5
    
} > ../system-report/hw.txt

# ===== 2. Réseau (IP, Routes, Ports) =====
echo "[2/3] Collecte réseau..."
{
    echo "=== INFORMATIONS RÉSEAU ==="
    echo "Date: $(date)"
    echo ""
    
    echo "--- INTERFACES & IP ---"
    ip a
    echo ""
    
    echo "--- ROUTES ---"
    ip r
    echo ""
    
    echo "--- PORTS EN ÉCOUTE (TCP) ---"
    ss -lntp 2>/dev/null
    echo ""
    
    echo "--- PORTS EN ÉCOUTE (UDP) ---"
    ss -lnup 2>/dev/null
    
} > ../system-report/net.txt

# ===== 3. Processus (Top 10) =====
echo "[3/3] Collecte processus..."
{
    echo "=== TOP 10 PROCESSUS ==="
    echo "Date: $(date)"
    echo ""
    
    echo "--- Par utilisation CPU/MEM ---"
    ps aux --sort=-%cpu | head -11
    echo ""
    
    echo "--- Résumé top ---"
    top -b -n 1 | head -20
    
} > ../system-report/proc.txt

echo "Collecte terminee!"
echo "Fichiers generes:"
ls -lh ../system-report/
