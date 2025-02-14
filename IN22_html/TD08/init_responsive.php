<?php

function init_responsive($styles, $choix){
    $tab = array();
    foreach($choix as $media => $v){
        if (isset($styles[$v])){
            $tab[] = array('href' => $styles[$v], 'media' => $media);
        }
    }
    return $tab;
}

?>