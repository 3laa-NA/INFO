<?php
define('RE_ENTETE', "/^([A-Z][A-Za-z]*(?:-[A-Z][A-Za-z]+)?):\s+(.*?)\s*$/");


define('EXEMPLE_ENTETE_1', 'Content-Type: text/plain ; charset=utf-8');

if (preg_match(RE_ENTETE, EXEMPLE_ENTETE_1, $m)) var_dump($m);
else echo "echec";

?>