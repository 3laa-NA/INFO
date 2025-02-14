<?php

function tableau_en_table($tab, $nom){

  if (!$tab) return '';

  $chaine = "";

  foreach ($tab as $k => $v){
    $chaine .= "<tr>\n<td>$k</td>\n<td>$v</td>\n</tr>\n";
  }
  $th = "<tr>\n<td>Nom</td>\n<td>Valeur</td>\n</tr>\n";

  return "<table>\n<caption>$nom</caption>\n$th$chaine$th</table>\n";
}

function cherche_index_n($tab, $n){
  
  foreach($tab as $k => $v){
    if(!--$n) return $k;
  }

  return false;
}

/*$Scores = array("candidatA"=>130,"candidatB"=>300,"candidatC"=>30);
echo tableau_en_table($Scores, 'scores'), "\n";
echo cherche_index_n($Scores, 2), "\n";
*/

?>