<?php
/// Exemple: afficher la profondeur d'imbrication.
include '../../TM/6/phraser.php';
class sax_prof implements preneurs_sax
{
    private $prof = 0;
    function ouvrante ($phraseur, $nom, $attr)
    	{$this->prof++; echo $this->prof, " <$nom>\n";}
    function fermante ($phraseur, $nom)
	    {echo $this->prof, " </$nom>\n", $this->prof--;}
    function texte ($phraseur, $texte)
    	{if (trim($texte)) echo $this->prof, " $texte\n";}
    function retour ($msg)
    {return $msg;}
}
/*// Test
var_dump(phraser('carnet.xml', new sax_prof));
//*/
?>