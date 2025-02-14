<?php

function fusion_ics($f1, $f2){

    if(!is_array($f1))
        $f1 = file($f1);
    if(!is_array($f2))
        $f2 = file($f2);

    if (!$f1)
        return $f2;
    if (!$f2)
        return $f1;

    array_pop($f1);

    array_shift($f2);
    while($f2 AND !preg_match("/^BEGIN:/",$f2[0])){
        array_shift($f2);
    }

    return array_merge($f1,$f2);
}

?>