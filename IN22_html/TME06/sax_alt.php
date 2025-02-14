<?php

include '/home/alaana/INFO-main/IN22_html/TME02/re_chemin.php';
include 'sax_echo.php';

class sax_alt extends sax_echo{

    function tableau_en_attributs($tab, $nom){
        if($nom == 'img' AND !isset($tab['alt'])){
            if (isset($tab['src']) AND preg_match(RE_CHEMIN, $tab['src'], $m))
                $tab['alt'] = htmlspecialchars($m[2]);
            else $tab['alt'] = 'inconnu';
        }
        return parent::tableau_en_attributs($tab, $nom);
    }
}

?>