<?php

include "/home/alaana/INFO-main/IN22_html/TD03/specialchars_en_table.php";
include "/home/alaana/INFO-main/IN22_html/TD03/html_form.php";
include "/home/alaana/INFO-main/IN22_html/TME02/debut_html.php";

$titre = "Formulaire avec textarea";

if(isset($_POST["jour"]) and isset($_POST["url"])){
    $body = specialchars_en_table($_POST, "Informations");
}else{
    $body = "<label for='jour'>Jour</label> <input id='jour' name='jour'/>\n"
    . "<label for='url'>Url</label><textarea id='url' name='url'></textarea>\n";

    $body = html_form($body . "<input type='submit'>");
}

echo debut_html($titre), "<body><div><h1>$titre</h1>\n$body</div></body></html>\n";

?>