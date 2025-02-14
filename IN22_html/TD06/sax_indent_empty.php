<?php

include '/home/alaana/INFO-main/IN22_html/TME02/re_chemin.php';
include 'phraser.php';

class sax_indent_empty implements preneurs_sax{

    private $prof = '';
    private $ferme = false;
    private $contenu = array('' => '');

    function ouvrante ($phraseur, $nom, $attr)
    {
        echo rtrim($this->contenu[$this->prof]);
        if ($this->prof) echo "\n", $this->prof;
        $this->contenu[$this->prof] = "";
        $this->prof .= '  ';
        echo "<$nom", $this->tableau_en_attributs($attr);
        $this->$ferme = true;
        $this->contenu[$this->prof]= "";
    }
    function fermante ($phraseur, $nom)
    {   
        
        $t = $this->contenu[$this->prof];
        $this->prof = substr($this->prof, 2);

        if($this->$ferme) echo '/>';
        else {
            echo rtrim($t);#, "\n" . $this->prof;
            echo "</", $nom, ">";
        }

        $this->ferme = false;
    }
    function texte ($phraseur, $texte)
    {
        if ($this->ferme) {
            echo '>';
            $this->ferme = false;
        }
        $this->contenu[$this->prof] .= $texte;
    }
    function retour ($msg)
    {
        echo "\n"; return $msg;
    }
    function tableau_en_attributs (array $attr)
    {
        $atts = '';
        $sep = ' ';
        foreach($attr as $k => $v) {
            $atts .= $sep . "$k='" . htmlspecialchars($v) . "'";
            $sep = "\n" . $this->prof;
        }
        return $atts;
    }
}

/*//Test
var_dump(phraser('carnet.xml', new sax_indent_empty));
//*/

?>