<?php
function libre_ics ($jour, $debut, $fin, $lines)
{
    $re = '/^DT(START|END).*:'.$jour.'T(.*)$/';
    $duree = array();
    foreach ($lines as $l) {
	    if (preg_match($re, $l, $a)){
            /// associer la date à l'index START ou END 
            $duree[$a[1]] = $a[2];
            /// si on a les 2, on peut tester
            if (count($duree) == 2) {
                if (($duree['START'] < $fin) AND ($duree['END'] > $debut)) {
                    return false;
                }
                /// remise à vide pour le suivant
                $duree = array();
            }
        } elseif (preg_match('/^END:VEVENT/', $l))
              // pour le cas du DTEND absent dans l'événément.
              $duree = array();
    }
    include 'rdv_ics.php';
    include 'fusionne_ics.php';
    return fusionne_ics($lines, rdv_ics($jour, $debut, $fin, "RDV"));
}
?>
