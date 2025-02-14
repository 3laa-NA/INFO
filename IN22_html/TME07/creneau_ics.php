<?php
include '/home/alaana/INFO-main/IN22_html/TD02/re_jour.php';
include '/home/alaana/INFO-main/IN22_html/TD02/re_heure.php';
include '/home/alaana/INFO-main/IN22_html/TD03/saisie_fiable.php';
include '/home/alaana/INFO-main/IN22_html/TME02/debut_html.php';

$jour = saisie_fiable($_POST, 'jour', RE_JOUR);
$fin = saisie_fiable($_POST, 'fin',  RE_HEURE);
$debut = saisie_fiable($_POST, 'debut', RE_HEURE);
$file = empty($_FILES['ICS']['tmp_name']) ? '' :
     (is_readable($_FILES['ICS']['tmp_name']) ? $_FILES['ICS']['tmp_name'] : '');
if (!$file OR $jour OR $debut OR $fin) {
    echo debut_html('RDV'), "<body>\n";
    include 'creneau.html';
    echo "</body></html>\n";
} else {
    include 'libre_ics.php';
    include 'envoi_ics.php';
    $cal = libre_ics($_POST['jour'], $_POST['debut'], $_POST['fin'], file($file));
    envoi_ics($cal, $cal ? 'rdv.ics' : 'Pas libre');
}
?>
