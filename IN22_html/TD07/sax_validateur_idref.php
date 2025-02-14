<?php

include 'sax_validateur_contenu.php';

class sax_validateur_idref extends sax_validateur_contenu{

    public $ids = array();
    public $idrefs = array();

    function controle_attributs($phraseur, $nom, $attr)
    {
        foreach ($this->dtd[$nom][1] as $att => list($type, $mode)) {
            if (isset($attr[$att])) {
                unset($attr[$att]);
            } elseif ($mode == 'REQUIRED') {
                $this->erreur($phraseur, "Attribut $att de $nom absent");
            }
        }
        if ($attr) {
            $msg = join(" ", array_keys($attr)) . " attributs de $nom inconnus";
            $this->erreur($phraseur, $msg);
        }
    }

    function retour ($msg)
    {
        $err = '';
        foreach($this->idrefs as $k->$v){
            if (!isset($this->ids[$k])){
                $this->les_erreurs[]= "ID $k manquant référencé ligne $v";
            }
        }
        if ($msg)
            $this->les_erreurs[]= $msg;
        return join("\n", $this->les_erreurs);
    }

}

?>