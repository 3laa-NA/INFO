<?php

include "limiter_cache.php";
include "typer_cache.php";

function trouver_cache($rep, $nom){
    if(is_readable("$rep/$nom.http")){
        
        $entetes = unserialize(file_get_contents("$rep/$nom.http"));      
        if(!limiter_cache($entetes)){
            $type = typer_cache($entetes);
            if(is_readable("$rep/$nom.$type")){
                return array("200", $entetes, file_get_contents("$rep/$nom.$type"));
            }
        }
    }
    
    return array();    
}

?>