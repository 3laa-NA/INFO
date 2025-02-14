<?php
/// Une expression rationnelle reconnaissant et décomposant une URL par:
/// 1: le schema
/// 2: le serveur
/// 3: le port
/// 4: le chemin de la ressource
/// 5: la Query-String

/// 1e etape: supposer que tout est présent
///define('RE_URL', "@^(\w+)://([^/:]*):(\d+)(/[^?]*)[?](.*)$@");
/// 2e etape: autoriser les absences sans ajouter des sous-chaines
define('RE_URL', "@^(?:(\w+)://)?([^/:]*)(?::(\d+))?(/[^?]*)[?]?(.*)$@");

/*// Test
$x =""; if (preg_match(RE_URL, $x, $r)) {echo $x,"\n"; var_dump($r);}
$x ="/"; if (preg_match(RE_URL, $x, $r)) {echo $x,"\n"; var_dump($r);}
$x ="foo.php?x=1"; if (preg_match(RE_URL, $x, $r)) {echo $x,"\n"; var_dump($r);}
$x ="http://foo.net/"; if (preg_match(RE_URL, $x, $r)) {echo $x,"\n"; var_dump($r);}
$x ="http://foo.net:8080/~1000000/index.html"; if (preg_match(RE_URL, $x, $r)) {echo $x,"\n"; var_dump($r);}
$x ="http://foo.net:8080/bar.php?x=1"; if (preg_match(RE_URL, $x, $r)) {echo $x,"\n"; var_dump($r);}
//*/
?>