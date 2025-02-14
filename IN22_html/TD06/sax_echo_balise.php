<?php
include '/home/alaana/INFO-main/IN22_html/TME02/debut_html.php';
include 'phraser.php';

class sax_echo_balise implements preneurs_sax
{
    function ouvrante ($phraseur, $nom, $attr)
    {
        echo "<div style='color:red'>Ouverture de : </div>";
        echo "$nom<br />\n";
    }
    function fermante ($phraseur, $nom)
    {
        echo "<div style='color:red'>Fermeture de : </div>";
        echo "$nom<br />\n";
    }
    function texte ($phraseur, $texte)
    {
        if (trim($texte) == ""){
            echo "<div style='color:orange'>Séparateurs pour mise en page</div>";
        } else {
            echo "<div style='color:blue'>R&eacute;ception du texte : </div>";
            echo $texte . "<br/>\n";
        }
    }
    
    function retour ($msg)
    {return $msg;}
}
/*// Test
var_dump(phraser('/home/alaana/INFO-main/IN22_html/TD06/carnet.xml', new sax_echo_balise));
//*/
?>