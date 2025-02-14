<?php

include "/home/alaana/INFO-main/IN22_html/TD03/html_form.php";
include "/home/alaana/INFO-main/IN22_html/TME02/debut_html.php";
include "/home/alaana/INFO-main/IN22_html/TD02/tableau_en_table.php";
include "/home/alaana/INFO-main/IN22_html/TME03/destinations.php";
include "/home/alaana/INFO-main/IN22_html/TME03/soumission_multiple.php";
include "/home/alaana/INFO-main/IN22_html/TME03/trouver_sous_index.php";

define('DIR_COOKIE', '/tmp/');

function cookie_file($n){
    $ch = ($_SERVER['REMOTE_ADDR']) . ($_SERVER['HTTP_USER_AGENT']) . $n;
    return md5($ch);
}

function memorise_cookie($duree){
    if(!isset($_COOKIE['visite_mem'])){
        $A = mt_rand();
        $nom = cookie_file($A);
        $F = DIR_COOKIE . $nom;
        $N = 0;

    } else {
        $nom = $_COOKIE['visite_mem'];
        $F = DIR_COOKIE . $nom;
        if(!is_readable($F)) return -1;
        list($N, $A) = file($file);
        if ($nom != cookie_file($A)) return -1;
    }

    if($duree){
        file_put_contents($F, ($N+1)."\n$A");
    }
    setcookie('visite_mem', $nom, array('expires'=>$duree, 'samesite'=>'Strict'));

    return $N;
}

$villes = trouver_sous_index($destinations, $pays);

$item = isset($_POST['item']) ? $_POST['item'] : 1;
$pays = isset($_POST['pays']) ? $_POST['pays'] : '';
$visit = isset($_POST['visit']) ? $_POST['visit'] : 1;
$v = memorise_cookie(is_numeric($item)? (time() + 604800): 0);

if (!$villes) {
    header("HTTP/1.1 303");
    header("Location: form_pays.php");

} if ($v == -1){
    header("HTTP/1.1 403");
    echo "Destruction ou vol de cookie\n";

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
        
    }

    echo debut_html($titre), "<body><div><h1>$titre</h1>\n$body</div></body></html>\n";
}


?>