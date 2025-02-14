<?php

include 'sax_input.php';

class sax_table extends sax_input {
    
    protected $tr = 0;

    function ouvrante ($phraseur, $nom, $attr)
    {
        if ($nom == 'table') $this->tr = 0;
        elseif ($nom == 'tr') $this->tr++;
        elseif (($nom == 'td') AND ($this->tr==1)) $nom = 'th'; 
        parent::ouvrante ($phraseur, $nom, $attr);
    }

    function fermante ($phraseur, $nom)
    {
        if (($nom == 'td') AND ($this->tr ==1))
            $nom = 'th';
        parent::fermante ($phraseur, $nom);
    }
}

/*// Test
var_dump(phraser('test.html', new sax_table));
//*/

?>