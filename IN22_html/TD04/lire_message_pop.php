<?php

function lire_message_pop($sock){
    $res = "";
    while( ($ch = fgets($sock)) != ".\n"){
        $res .= $ch;
    }

    return $res;
}

?>