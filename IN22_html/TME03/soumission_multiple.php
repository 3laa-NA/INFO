<?php

include "/home/alaana/INFO-main/IN22_html/TD02/tableau_en_liste.php";


function soumission_multiple($tab,$n){
    if($n>count($tab) or $n<1) $n=1;

    $a = ($n==1) ? '': "<input value='n-1' name='item' type='submit'/>";
    $c = ($n>=count($tab)) ? '': "<input value='n+1' name='item' type='submit'/>";

    $destination = cherche_index_n($tab, $n);
    $prix = $destination ? $tab[$destination] : "?";
    $v = htmlspecialchars($destination, ENT_QUOTES);

    $b = "<input value='$v' name='item' type='submit'/>$prix €";


    return tableau_en_liste(array($a, $b, $c));

}

?>