<?php

include 'sax_title.php';

class sax_input extends sax_title{

    protected $label = '';

    function ouvrante($phraseur, $nom, $attr){
        if($nom == 'label'){
            $label = $attr['for'];
        }
        if($nom == 'input' AND isset($attr['name'])){
            if ($label != ''){
                $attr['id'] = $label;
            }else{
                $v = $attr['value'];

                if(isset($attr['id'])){
                    $id = $attr['id'];
                }else{
                    $id = $attr['name'];
                    $attr['id'] = $id;
                }
                echo "<label for= '$id'>$v</label>";
            }
        }
        parent::ouvrante($phraseur, $nom, $attr);
    }
}

?>