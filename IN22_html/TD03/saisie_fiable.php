<?php

function saisie_fiable($tab, $index, $exp_ra=''){
    if(!isset($tab[$index])) return 1;

    if(!($exp_ra == '')){
        if(!preg_match($exp_ra, $tab[$index])) return -1;
    }

    return 0;
}

?>
