<?php 

include "/home/alaana/INFO-main/IN22_html/TD03/html_form.php";
include "/home/alaana/INFO-main/IN22_html/TME02/debut_html.php";
include "/home/alaana/INFO-main/IN22_html/TD02/tableau_en_liste.php";
include "/home/alaana/INFO-main/IN22_html/TD03/tableau_pour_cocher.php";

$villes = array('Paris', 'Lyon', 'Marseille'); // pour essai

if (isset($_GET['choix']) AND is_array($_GET['choix'])) {
    header('Content-Type: text/plain');
    foreach ($_GET['choix'] as $n => $v) echo $villes[$n], "\n";
} else {
    $titre = "Possibilités";
    $body = tableau_en_liste(tableau_pour_cocher($villes));
    $body = html_form($body , 'get', '', " onsubmit='return submitInAjax(this)'");
}
echo debut_html($titre),
    "<body><div><h1>$titre</h1>\n$body"
    ."<script type='text/javascript' src='ajax.js'></script>
    <script type='text/javascript' src='submitInAjax.js'></script>
    <script type='text/javascript' src='listeChaine.js'></script>
    <script type='text/javascript' src='insereAjax.js'></script>\n"
    ."</div></body></html>\n";
?> 