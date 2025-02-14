<?php

/// Noter l'homonymie sur Aix (Aix-La-Chappelle en Allemagne et beaucoup d'autres en France)
/// et la présence d'apostrophes dans certains noms.



include "/home/alaana/INFO-main/IN22_html/TD03/html_form.php";
include "/home/alaana/INFO-main/IN22_html/TME02/debut_html.php";
include "/home/alaana/INFO-main/IN22_html/TME03/tableau_en_select.php";
include "/home/alaana/INFO-main/IN22_html/TME03/destinations.php";

$title = "Pays";
$body = tablaeu_en_select($destinations,"pays") . "<input type='submit'/>";
$body = html_form($body,'post','form_ville.php');

echo debut_html($title) . "<body><div><h1>$title</h1>$body</div></body></html>\n" ;

?>