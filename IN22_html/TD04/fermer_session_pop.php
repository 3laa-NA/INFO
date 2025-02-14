<?php

include "/home/alaana/INFO-main/IN22_html/TD04/requeter_en_pop.php";

function fermer_session_pop($sock){
    requeter_en_pop($sock, "QUIT");
    @fclose($sock);
}

?>