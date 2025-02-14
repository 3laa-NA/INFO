<?php

include '/home/alaana/INFO-main/IN22_html/TME02/re_chemin.php';
include 'phraser.php';

class sax_indentation implements preneurs_sax{

    private $prof = '';
    private $contenu = array('' => '');

    function ouvrante ($phraseur, $nom, $attr)
    {
        echo rtrim($this->contenu[$this->prof]);
        if ($this->prof) echo "\n", $this->prof;
        $this->contenu[$this->prof] = "";
        $this->prof .= '  ';
        echo "<$nom", $this->tableau_en_attributs($attr) ,'>';
        $this->contenu[$this->prof]= "";
    }
    function fermante ($phraseur, $nom)
    {
        $t = $this->contenu[$this->prof];
        $this->prof = substr($this->prof, 2);
        echo rtrim($t);#, "\n" . $this->prof;
        echo "</", $nom, ">";
    }
    function texte ($phraseur, $texte)
    {
        $this->contenu[$this->prof] .= $texte;
    }
    function retour ($msg)
    {
        echo "\n"; return $msg;
    }
    function tableau_en_attributs (array $attr)
    {
        $atts = '';
        foreach($attr as $k => $v)
            $atts .= "\n" . $this->prof . "$k='" . htmlspecialchars($v) . "'";
        return $atts;
    }
}

/*// Test
var_dump(phraser('carnet.xml', new sax_indentation));
//*/

?>