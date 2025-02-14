<?php

function fournir_page($tab){
    header("HTTP/1.1 $tab[0]");
    foreach ($tab[2] as $nom => $entetes){
        foreach ($entetes as $entete){
            header ("$nom: $entete");
        }
    }
    echo tab[2];
}

?>