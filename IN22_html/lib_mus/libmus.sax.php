<?php

class libmus_sax implements preneurs_sax{
    public $res = array("albums" => array(), "artistes" => array());
    public $alb = '';
    public $art = '';
    function ouvrante ($phraseur, $nom, $attr)
    {
        if($nom == 'album'){
            $a = $this->res[0][$attr['id']] = array();
            $this->alb = $attr['id'];

        } elseif($nom == 'artiste'){
            $a = $this->res[1][$attr['id']] = array();
            $this->art = $attr['id'];

        } else {
            if($this->alb){
                $this->alb = "[$this->alb][$nom]";
            }
        }
        
        foreach($attr as $k=>$v){
            if($k != 'id'){
                $a[$k] = $v;
            }
        }

        
    }
    function fermante ($phraseur, $nom)
    {
        if($nom == 'album'){
            $alb = '';
        }
        if($nom == 'artiste'){
            $art = '';
        }
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

?>