<?php

function actualiser($t, $f, $d, $n){
    $t[$f] = time();

    while(count($t) > $n){
        asort($t);
        $nom = key($t);
        $entetes = unserialize(file_get_contents("$rep/$nom.http"));
        $type = typer_cache($entetes);

        unlink("$rep/$nom.http");
        unlink("$rep/$nom.$type");

        array_shift($t);
    }

    return $t;
}

?>