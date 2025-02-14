<?php

/// [1]: nom de la balise [2]: son contenu
define('RE_DTD_ELEMENT', "@<!ELEMENT\s+([\w:-]+)\s*([^>]*)\s*>@");
/// [1]: nom de la balise [2]: ses attributs
define('RE_DTD_ATTLIST', "@<!ATTLIST\s+([\w:-]+)\s*([^>]*)\s*>@");
/// [1]: nom de l'attribut [2]: son type [3]: son mode
define('RE_DTD_ATTRIBUTE', "@([\w:-]+)\s*(.*?)\s*#(\w+)@");

function analyse_dtd($dtd){
    $elements = array();

    if(preg_match_all(RE_DTD_ELEMENT, $dtd, $m, PREG_SET_ORDER)){
        foreach($m as list(,$balise, $contenu)){
            $elements[$balise] = array($contenu, array());
        }
    }
    if(preg_match_all(RE_DTD_ATTLIST, $dtd, $m, PREG_SET_ORDER)){
        foreach($m as list(,$balise, $contenu)){
            if(preg_match_all(RE_DTD_ATTRIBUTE, $contenu, $r, PREG_SET_ORDER)){
                foreach($r as list(,$nom, $type, $mode)){
                    $elements[$balise][1][$nom] = array($type, $mode);
                }
            }
        }
    }

    return $elements;
}

?>