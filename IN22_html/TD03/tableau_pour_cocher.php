<?php 

/// $tab est un tableau indice (alpha-)numeriquement
/// $nom est le nom souhaité pour la saisie
/// $mode est:
///  - soit un des indices de $tab, et on veut alors un choix unique;
///  - soit un tableau dont les indices forment un sous-ensemble de ceux de $tab
///  qui indiquent les cases à cocher d'avance

function tableau_pour_cocher($tab, $nom='choix', $mode=array())
{
    $res = array();
    if (is_array($mode)) {
        $type = 'checkbox';
    } else {
        $type = 'radio';
        $mode = array($mode => true);
    }
    foreach($tab as $k => $v) {
        $c = isset($mode[$k]) ? " checked='checked'" : '';
        $indice = ($type == 'radio') ? '' : "[$k]";
        $res[]= "<input id='$nom$k' value='$v' name='$nom$indice' type='$type'$c />"
               ."<label for='$nom$k'>$v</label>\n";
    }
    return $res;
}

?>