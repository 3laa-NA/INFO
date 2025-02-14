<?php

include "/home/alaana/INFO-main/IN22_html/TD03/html_form.php";
include "/home/alaana/INFO-main/IN22_html/TME02/debut_html.php";
include "/home/alaana/INFO-main/IN22_html/TD02/tableau_en_table.php";
include "/home/alaana/INFO-main/IN22_html/TME03/destinations.php";
include "/home/alaana/INFO-main/IN22_html/TME03/soumission_multiple.php";
include "/home/alaana/INFO-main/IN22_html/TME03/trouver_sous_index.php";

session_start(array('cookie_lifetime' => 3600 * 24));

function protege_cookie($duree){
    if (!isset($_SESSION['visite'])) {
        $_SESSION['visite'] = 0;
        $_SESSION['REMOTE_ADDR'] = $_SERVER['REMOTE_ADDR'];
        $_SESSION['HTTP_USER_AGENT'] = $_SERVER['HTTP_USER_AGENT'];
    } else {
        if ($_SESSION["REMOTE_ADDR"] != $_SERVER['REMOTE_ADDR'] OR
            $_SESSION["HTTP_USER_AGENT"] != $_SERVER['HTTP_USER_AGENT']) {
            header('HTTP/1.1 403 Forbidden');
            die('Vol de cookie mon gaillard');
        }
    }
    return $_SESSION['visite']++;
}

$villes = trouver_sous_index($destinations, $pays);

$item = isset($_POST['item']) ? $_POST['item'] : 1;
$pays = isset($_POST['pays']) ? $_POST['pays'] : '';
$visit = isset($_POST['visit']) ? $_POST['visit'] : 1;
$v = protege_cookie();

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
        if (isset($villes[$item])){
            $body = "Bon séjour à $item pour " . $villes[$item]*$visit . "€.";
            
        } else $body = "Ville inconnue";
        setcookie(session_name(), '',  array('samesite' => 'Strict', 'expires' => 0));
        unset($_SESSION);
    }

    echo debut_html($titre), "<body><div><h1>$titre</h1>\n$body</div></body></html>\n";
}


?>