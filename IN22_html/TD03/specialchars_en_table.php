<?php
/// La fonction demandee est presque "tableau_en_table"
/// sauf qu'il faut neutraliser les caracteres speciaux.
include "/home/alaana/INFO-main/IN22_html/TD02/tableau_en_liste.php";
include "/home/alaana/INFO-main/IN22_html/TD02/tableau_en_table.php";

function specialchars_en_table($tab, $nom)
{
  $r = array();
  /// Le tableau etant des saisies de l'utilisateur
  /// il faut se mefier de ce qu'il a pu ecrire comme "<" etc
  /// y compris pour les index qui peuvent resulter d'une query-string ad hoc.
  /// Dans le cas de saisies indicees, on applatit
  // (mais il faudrait le faire récursivement pour plus de sûreté)
  foreach ($tab as $k => $v)
    $r[htmlspecialchars($k)] = htmlspecialchars(is_array($v) ? join("\n", $v):$v);
  /// A l'inverse, la legende etant fournie par le programmeur
  /// on fait confiance aux chevrons qui y figurent, on ne transcode pas.
  /// cf exemple ci-dessous
  return tableau_en_table($r, $nom);
}

/*
//Test
include '/home/alaana/INFO-main/IN22_html/TME02/debut_html.php';
echo debut_html('Saisies en table'), '<body>';
$caption = '<a href="https://www.php.net/manual/fr/reserved.variables.get">$_GET</a> : '. htmlspecialchars($_SERVER['QUERY_STRING']);
echo specialchars_en_table($_GET, $caption);
echo "</body></html>\n";
//
*/
?>