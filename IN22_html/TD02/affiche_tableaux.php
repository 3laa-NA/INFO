<?php

$candidats = array("Bob", "Alice", "Chris");

echo "<h1>Liste avec for</h1>\n<ul>\n";
for ($i=0; $i<count($candidats); $i++){
  echo "<li>", $candidats[$i], "</li>\n";
}
echo "</ul>\n";


echo "<h1>Liste avec foreach</h1>\n<ul>\n";
foreach ($candidats as $elt){
  echo "<li>", $elt, "</li>\n";
}
echo "</ul>\n";


echo "<h1>Liste avec while</h1>\n<ul>\n";
while($candidats){
  echo "<li>", array_shift($candidats),"</li>\n";
}
echo "</ul>\n";

$Scores = array("Bob"=>300, "Alice"=>130, "Chris"=>30);

arsort($Scores);
echo "<h1>Liste score avec foreach</h1>\n<ol>\n";
foreach ($Scores as $nom=>$score){
  echo "<li>", $nom, ": ", $score, "</li>\n";
}
echo "</ol>\n";


?>
