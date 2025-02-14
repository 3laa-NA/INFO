
<?php
include 'phraser.php';
class sax_echo implements preneurs_sax
{
    function retour ($msg) {echo "\n"; return $msg; }
    function fermante ($phraseur, $nom) {echo "</$nom>";}
    function texte ($phraseur, $texte) {echo $texte;}
    function ouvrante ($phraseur, $nom, $attr)
    {
        echo "<", $nom, $this->tableau_en_attributs($attr, $nom),  ">";
    }
    function tableau_en_attributs ($tab, $nom)
    {
        $atts = '';
        foreach($tab as $k => $v) $atts .= " $k='" . htmlspecialchars($v) . "'";
        return $atts;
    }
}
/// Test phraser('test.html', new sax_echo);
?>
