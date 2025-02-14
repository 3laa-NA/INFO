<?php

function trouver_sous_index($tab, $index){
    foreach ($tab as $k => $v){
        if (isset($v[$index])) {
            return $v[$index];
        }
    }
    return array();
}

?>