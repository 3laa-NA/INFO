<?php

include "trouver_cache.php";
include "memoriser_cache.php";
include "fournir_page.php";
include "/home/alaana/INFO-main/IN22_html/TME04/requeter_en_http.php";

function utiliser_cache($url, $rep){
    $nom = md5($url);
    $reponse = trouver_cache($nom);
    $res = $nom;


    if(!$reponse){
        list($code, $entetes, $page) = requeter_en_http($url);
        $res = '';
        if ($reponse[0] == 200 AND limiter_cache($reponse[1])){
            memoriser_cache($rep, $nom, $reponse[1], $reponse[2]);
            $res = $nom;
        }
    }

    fournir_page($reponse);

    return $res;
}

?>