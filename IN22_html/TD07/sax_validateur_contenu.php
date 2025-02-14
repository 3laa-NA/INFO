<?php

include 'sax_validateur_min.php';

class sax_validateur_contenu extends sax_validateur_min{

    public $pile = array();

    function ouvrante ($phraseur, $nom, $attr)
    {
        if (!isset($this->dtd[$nom])) {
            $this->erreur($phraseur, "Element $nom inconnu");
            $this->pile[] = '';
            
        }else {
            
            if(!$this->pile){
                if ($nom != key($dtd)) {
                    $this->les_erreur($phraseur, "balise $nom invalide");
                }

            }else{
                if(!preg_match("@.*$nom.*@", $this->pile[count($this->pile)-1])){
                    $this->les_erreur($phraseur, "contenu $nom invalide");
                }
            }
        }
        
    }

    function fermante ($phraseur, $nom){
        array_pop($this->pile);
    }

    function texte ($phraseur, $texte){
        if(trim($texte) AND !preg_match( "@.*#PCDATA.*@" , $this->pile[count($this->pile)-1])){
            $this->erreur($phraseur, "absence de #PCDATA");
        }
    }

}

?>