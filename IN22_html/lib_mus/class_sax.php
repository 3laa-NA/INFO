<?php
interface preneurs_sax
{
    function ouvrante (XmlParser $phraseur, string $name, array $attrs) : void;
    function fermante (XmlParser $phraseur, string $name) : void;
    function texte    (XmlParser $phraseur, string $texte) : void;
    function retour   (string $msg) : mixed;
}
?>
