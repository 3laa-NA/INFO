<?php

function tablaeu_en_select($options, $nom, $choix = ''){
    $sel = "<label for='$nom'>$nom</label><select id='$nom' name='$nom'>";

    foreach($options as $titre => $listes){
        $t = htmlspecialchars($titre, ENT_QUOTES);
        $sel .= "\n<optgroup label ='$t'>";
        foreach($listes as $indice => $valeur){
            $c = ($indice == $choix) ? " selected='selected'" : "";
            $desc = is_string($valeur) ? $valeur : $indice;
            $sel .= "\n<option value='$indice'$c>$desc</option>";
        }
        $sel .= "\n</optgroup>";
    }

    return $sel."\n</select>\n";
}

?>