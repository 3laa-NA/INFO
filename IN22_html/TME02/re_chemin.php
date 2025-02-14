<?php

/// Une expression rationnelle reconnaisant et decomposant un chemin d'acces par:
/// 1: le répertoire
/// 2: le nom du fichier sans son extension éventuelle
/// 3: l'extension éventuelle
/// De plus les caractères réservés d'Unix ne sont pas tolérés

$nunix =  "][(){}<>|&;'\"";
define('RE_CHEMIN', "@^([^$nunix]*?)([^$nunix/]*?)(?:[.]([\d\w]+))?$@");

/*// Test
if (preg_match(RE_CHEMIN, "makefile", $r)) var_dump($r);
if (preg_match(RE_CHEMIN, "exo1.php", $r)) var_dump($r);
if (preg_match(RE_CHEMIN, "/bin", $r)) var_dump($r);
if (preg_match(RE_CHEMIN, "/bin/ls", $r)) var_dump($r);
if (preg_match(RE_CHEMIN, "index.fr.php", $r)) var_dump($r);
if (preg_match(RE_CHEMIN, ".bashrc", $r)) var_dump($r);
if (preg_match(RE_CHEMIN, "/~1000000/exo1.php", $r)) var_dump($r);
//*/

?>