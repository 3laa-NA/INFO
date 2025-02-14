<?php

include "/home/alaana/INFO-main/IN22_html/TME02/debut_html.php";
include "/home/alaana/INFO-main/IN22_html/TD03/specialchars_en_table.php";
include "/home/alaana/INFO-main/IN22_html/TD04/choisir_message_pop.php";
include "/home/alaana/INFO-main/IN22_html/TD04/ouvrir_session_pop.php";
include "/home/alaana/INFO-main/IN22_html/TD04/fermer_session_pop.php";

function presenter_message_pop($sock, $criters){
    $rep = choisir_message_pop($sock, $criters);
    $res = '';

    foreach ($rep as list($n, $entetes, $corps)){
        $res .= "<fieldest>" . specialchars_en_table($entetes, "Mail $n")
        ."<div>" . preg_replace("@\n@s", "<br />\n", htmlspecialchars($corps))
        . "</div></fieldest>\n";
    }
    return debut_html("Mails")
    . "<body>" . tableau_en_table($criters, "criters")
    . "<div>" . count($rep) . " message trouvés ". "</div>"
    . "</body></html>";
}

/// Test
/*
$sock = ouvrir_session_pop('127.0.0.1', 'moi', '123456789', 2110);
if (is_string($sock))
    echo $sock;
else {
    echo presenter_message_pop($sock,
            array("From" => "maman@ici.fr", "Subject" => "Noel"));
    fermer_session_pop($sock);
}
//*/

?>