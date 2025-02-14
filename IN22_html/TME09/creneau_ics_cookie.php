<?php

include '/home/alaana/INFO-main/IN22_html/TD02/re_jour.php';
include '/home/alaana/INFO-main/IN22_html/TD02/re_heure.php';
include '/home/alaana/INFO-main/IN22_html/TD03/saisie_fiable.php';
include '/home/alaana/INFO-main/IN22_html/TD08/debut_html.php';

$jour = saisie_fiable($_POST, 'jour', RE_JOUR);
$fin = saisie_fiable($_POST, 'fin',  RE_HEURE);
$debut = saisie_fiable($_POST, 'debut', RE_HEURE);
$file = empty($_FILES['ICS']['tmp_name']) ? '' :
      (is_readable($_FILES['ICS']['tmp_name']) ? $_FILES['ICS']['tmp_name'] : '');
if (!$file OR $jour OR $debut OR $fin) {
    /// Valeur d'expiration arbitraire, car le cookie sera supprimé par JS
    $options = array('samesite' => 'Strict', 'expires' => time()+3600);
    if ($jour < 0) setcookie("jour", "erreur", $options);
    if ($debut < 0) setcookie("debut", "erreur", $options);
    if ($fin < 0) setcookie("fin", "erreur", $options);
    if ($file === false) setcookie("ICS", "erreur", $options);
    echo debut_html('RDV', array(".erreur{border:2px dashed red}")),
        "<body onload='class_from_cookie()'>\n";
    include '/home/alaana/INFO-main/IN22_html/TME07/creneau.html';
    echo "<script type='text/javascript' src='class_from_cookie.js'></script>\n",
        "</body></html>\n";
} else {
    // suite inchangée (hormis les répertoires pour les inclusions)
    include '/home/alaana/INFO-main/IN22_html/TME07/libre_ics.php';
    include '/home/alaana/INFO-main/IN22_html/TME07/envoi_ics.php';
    $cal = libre_ics($_POST['jour'], $_POST['debut'], $_POST['fin'], file($file));
    envoi_ics($cal, $cal ? 'rdv.ics' : 'Pas libre');
}

?>