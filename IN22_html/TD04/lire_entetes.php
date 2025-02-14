<?php

define('RE_ENTETE', "/^([A-Z][A-Za-z]*(?:-[A-Z][A-Za-z]+)?):\s+(.*?)\s*$/");

function lire_entetes($sock){

    $res = array();
    $ind = '';
    while( ($ch = fgets($sock)) != "\n"){
        if(preg_match(RE_ENTETE, $ch, $tmp)){
            $ind = $tmp[1];
            if(!isset($res[$ind])){
                $res[$ind] = array($tmp[2]);
            }else{
                $res[$ind][] = $tmp[2];
            }
            
        } else {
            $res[$ind][count($res[$ind])-1] .= $ch;
        }   
        
    }

    return $res;
}

?>