<?php

include "/home/alaana/INFO-main/IN022_(html)/TD04/requeter_en_pop.php";
include "/home/alaana/INFO-main/IN022_(html)/TD04/lire_message_pop.php";
include "/home/alaana/INFO-main/IN022_(html)/TD04/lire_entetes.php";

function choisir_message_pop($sock, $tab){

    if ( ($req = requeter_en_pop($sock, "STAT")) == false){
        return;
    }
    
    $n = intval($req);
    $res = array();
    $n_msg = 0;

    for (int $i=0; $i<$n; ++$i){

        requeter_en_pop($sock, "RETR $i");
        $tmp_tab = lire_entetes($sock);

        $ok = true;
        foreach($tab as $en_t => $v){
            if($tmp_tab[$en_t][0] != $v){
                $ok = false;
                break;
            }
        }

        if($ok){
            $msg = lire_message_pop($sock);
            $res[$n_msg] = array ($n_msg,$tmp_tab,$msg);
            $n_msg++;
        }
        
    }

    return $res;

}

?>