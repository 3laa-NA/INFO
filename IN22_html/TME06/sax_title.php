<?php

include 'sax_alt.php';

class sax_title extends sax_alt{

    protected $t = array();

    function tableau_en_attributs($tab, $nom){
        if($nom == 'a' AND isset($tab['href'])){
            $href = $tab['href'];
            if (!isset(this->t[$href])){
                $title = 'Lien'. count(this->t)+1;
                if(isset($tab['title']) AND !array_search($tab['title'] , this->t)){
                    $title = $tab['title'];
                }
                $tab['title'] = $title;
                $this->t[$href] = $title;
            }else{
                $tab['title'] = this->t[$href];
            }
        }
        return parent::tableau_en_attributs($tab, $nom);
    }
}

?>