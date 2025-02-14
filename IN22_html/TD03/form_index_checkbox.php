<?php 

include "/home/alaana/INFO-main/IN22_html/TD03/html_form.php";
include "/home/alaana/INFO-main/IN22_html/TME02/debut_html.php";
include "/home/alaana/INFO-main/IN22_html/TD02/tableau_en_liste.php";
include "/home/alaana/INFO-main/IN22_html/TD03/tableau_pour_cocher.php";

$villes = array('Paris', 'Lyon', 'Marseille'); // pour essai

if (!isset($_GET['choix']) OR !is_array($_GET['choix'])) {
    $titre = "Possibilités";
    $body = tableau_en_liste(tableau_pour_cocher($villes, 'choix'));
    $body = html_form($body . "<input type='submit' />");
} else {
    $titre = "Choix effectués";
    $final = array();
    // Ne pas faire confiance aux valeurs transmises, repartir des index
    foreach ($_GET['choix'] as $n => $v) $final[] = $villes[$n];
    $body = tableau_en_liste($final);
}

echo debut_html($titre),
    "<body><div><h1>$titre</h1>\n$body</div></body></html>\n";
?>