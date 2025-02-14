<?php

include '/home/alaana/INFO-main/IN22_html/TD06/class_sax.php';
include 'analyse_dtd.php';

class sax_validateur_min implements preneurs_sax{
    public $dtd = array();
    public $les_erreurs = array();

    function __construct($fichier){
        if(is_readable($fichier)){
            $this->dtd = analyse_dtd(file_get_contents($fichier));
        }
    }

    function erreur($phraseur, $msg){
        if(!isset($this->les_erreurs[$msg])){
            $this->les_erreurs[$msg] = $msg . ", lignes:";
        }
        $this->les_erreurs[$msg] .= ' '. xml_get_current_line_number($phraseur);
    }

    function retour(){
        return join("\n", $this->les_erreurs);
    }



}

?>