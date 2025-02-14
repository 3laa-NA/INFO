<?php

// Repérer les lignes sans importance
define('RE_APACHE_VIDE', '/^\s*(#.*)?$/');
// Repérer les balises ouvrantes avec attribut implicite
define('RE_APACHE_BAL', '/^\s*<(\w+)\s+(["\']?)([^>]+)\2\s*(>)\s*$/');
// Repérer les textes non balisés
define('RE_APACHE_DIR', '/^\s*(\w+)\s+(["\']?)(.+)\2(.*?)\s*$/');

function pseudo_xml ($path)
{
  /// si l'argument n'est pas un fichier de configuration exploitable,
  /// on considère que l'argument est la configuration elle-même
  $text = is_readable($path) ? file($path) : array($path);
  $resultat = array("<CONF>");
  foreach($text as $l) {
      if (!preg_match(RE_APACHE_VIDE, $l)) {
          if (preg_match(RE_APACHE_BAL, $l, $a)
          OR  preg_match(RE_APACHE_DIR, $l, $a)) {
              list(,$bal, $delim, $val, $fin) = $a;
              if ($fin != '>') {
                  $val .= $fin;
                  $fin = " />";
              }
              $delim = strpos($val, '"') !== false ? "'" : '"';
              $l = "<$bal v=$delim$val$delim$fin\n";
          }
          $resultat[]= $l;
      }
  }
  $resultat[]= "</CONF>\n";
  return $resultat;
}

/*// Test
echo join('',pseudo_xml( "<foo x>"));
echo join('',pseudo_xml( "<foo 'x'>"));
echo join('',pseudo_xml( '<foo "x">'));
echo join('',pseudo_xml( "<foo '\"x'>"));
echo join('',pseudo_xml( '<foo "\'x">'));
echo join('',pseudo_xml( 'LogFormat "%h %l %u %t \"%r\" %>s %b \"%{Referer}i\" \"%{User-Agent}i\" %I %O" combinedio'));
foreach(pseudo_xml("/Users/esj/Sites/esj.conf") as $l) echo $l;
//*/

?>
