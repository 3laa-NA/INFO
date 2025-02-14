<?php

function html_form($corps, $method = 'get', $action = '', $att = ''){
    return "<form action='$action' method='$method'$att><fieldset>\n"
    . $corps
    . "\n</fieldset></form>\n";
}

/*
$test1 = html_form("alaa");
echo $test1;
*/
?>
