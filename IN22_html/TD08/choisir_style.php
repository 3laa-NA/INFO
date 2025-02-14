<?php

include '/home/alaana/INFO-main/IN22_html/TME03/tableau_en_select.php';
include '/home/alaana/INFO-main/IN22_html/TD02/tableau_en_liste.php';
include '/home/alaana/INFO-main/IN22_html/TD03/html_form.php';

function choisir_style ($files, $media, $courants)
{
    $body = '';
    $files = array($files);
    foreach($media as $medium) {
        $body .= tablaeu_en_select($files, $medium, $courants[$medium]);
    }
    return html_form($body . "<input type='submit' />", 'post');
}

?>