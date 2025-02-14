<?php

include '/home/alaana/INFO-main/IN22_html/TME02/debut_html.php';
include '/home/alaana/INFO-main/IN22_html/TD03/html_form.php';
include '/home/alaana/INFO-main/IN22_html/TD03/specialchars_en_table.php';
include '/home/alaana/INFO-main/IN22_html/TME04/requeter_en_http.php'; 

$titre = "Visualisation des en-têtes";

if(!isset($_GET['url'])){
    $body = html_form("<label for='url'>URL</label> <input id='url' name='url' size='99'/>");
} else {
    list($status, $entetes,) = requeter_en_http($_GET['url'], 'HEAD', '1.0');
    $body = specialchars_en_table($entetes, htmlspecialchars($_GET['url']) . " status $status");
}

echo debut_html($titre), "<body>$body</body></html>\n";
?>