<?php

include "/home/alaana/INFO-main/IN22_html/TD03/html_form.php";
include "/home/alaana/INFO-main/IN22_html/TME02/debut_html.php";
include "/home/alaana/INFO-main/IN22_html/TD02/tableau_en_table.php";
include "/home/alaana/INFO-main/IN22_html/TME03/destinations.php";
include "/home/alaana/INFO-main/IN22_html/TME03/soumission_multiple.php";
include "/home/alaana/INFO-main/IN22_html/TME03/trouver_sous_index.php";

$item = isset($_POST['item']) ? $_POST['item'] : 1;
$pays = isset($_POST['pays']) ? $_POST['pays'] : '';
$villes = trouver_sous_index($destinations, $pays);


if (!$villes) {
    header("HTTP/1.1 303");
    header("Location: form_pays.php");
} else {
    $titre = "Votre voyage";
    if (is_numeric($item)) {
        $pays = htmlspecialchars($pays, ENT_QUOTES);
        $hidden = "<input type='hidden' name='pays' value='$pays' />";
        $body = html_form(soumission_multiple($villes, $item) . $hidden, 'post');
    } else {
        if (isset($villes[$item]))
            $body = "Bon séjour à $item pour " . $villes[$item] . "€.";
        else $body = "Ville inconnue";
    }
    echo debut_html($titre),
        "<body><div><h1>$titre</h1>\n$body</div></body></html>\n";
}

?>