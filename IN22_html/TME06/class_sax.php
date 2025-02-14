<?php
interface preneurs_sax {
    function ouvrante ($phraseur, $nom, $attr);
    function fermante ($phraseur, $nom);
    function texte ($phraseur, $texte);
    function retour ($msg); // sert à donner le résultat final.
}
?>