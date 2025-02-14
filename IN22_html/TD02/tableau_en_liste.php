<?php

function tableau_en_liste($data, $type = "ul"){
    
    if (!is_array($data)) return $data;
    
    if (!$data) return 'lm';

    if(count($data) == 1) return array_shift($data);

    foreach( $data as $k => $v){
        $data[$k] = tableau_en_liste($v, $type);
    }

    return "<$type><li>" . join("</li>\n\t<li>", $data) . "</li></$type>\n";
}

$data = array(
    'Fruits' => array('Pomme', 'Banane', 'Orange'),
    'Légumes' => array('Carotte', 'Pomme de terre', 'Tomate'),
    'Autres' => array('Pain', 'Lait')
);


/*
// Appeler la fonction pour convertir le tableau en liste HTML
$liste_html = tableau_en_liste($data);

// Afficher la liste HTML
echo $liste_html;
*/
?>