<?php

include "typer_cache.php";

function memoriser_cache($nom_rep, $nom_fich, $entetes, $page){
    if(!file_put_contents("$nom_rep/$nom_fich.http", serialize($entetes))) return false;
    if(!file_put_contents("$nom_rep/$nom_fich." . typer_cache($entetes), $page)) return false;

    return true;
}

?>