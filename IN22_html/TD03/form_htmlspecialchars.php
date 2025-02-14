<?php

include "/home/alaana/INFO-main/IN22_html/TD03/specialchars_en_table.php";
include "/home/alaana/INFO-main/IN22_html/TD03/html_form.php";
include "/home/alaana/INFO-main/IN22_html/TME02/debut_html.php";
include "/home/alaana/INFO-main/IN22_html/TD02/re_jour.php";
include "/home/alaana/INFO-main/IN22_html/TME02/re_url.php";
include "/home/alaana/INFO-main/IN22_html/TD03/saisie_fiable.php";

$url = saisie_fiable($_POST, "url", $RE_URL);
$jour = saisie_fiable($_POST, "jour", $RE_JOUR);
$titre = "Evenement";
$err = '';

if (!$url AND !$jour){
    $body = specialchars_en_table($_POST, "Informations");
} else {
    if($url < 0) $err = ' url';
    $url = ($url > 0) ? '' : htmlspecialchars($_POST['url']);

    if($jour < 0) $err .= ' jour';
    $jour = ($jour > 0) ? '' : htmlspecialchars($_POST['jour']);

    $body = "<label for='jour'>Jour :</label>" .
          "<input id='jour' name='jour' value='$jour' />\n" .
          "<label for='url'>Url :</label>" .
          "<textarea id='url' name='url'>$url</textarea>\n";
    $body = html_form($body . "<input type='submit'>");;
}

echo debut_html($titre), "<body><div><h1>$titre</h1>\n$body</div></body></html>\n";

?>