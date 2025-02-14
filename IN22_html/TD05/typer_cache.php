<?php

define ("RE_CONTENT_TYPE", "@/(\w+)@");

function typer_cache($entetes){

    if (isset($entetes['Content-Type']) AND preg_match(RE_CONTENT_TYPE, $entetes['Content-Type'][0], $m)) return $m[1];

    return "html";
}

/*// Test
if (preg_match(RE_CONTENT_TYPE, 'text/ics;charset=utf-8', $m)) echo $m[1], "\n";
if (preg_match(RE_CONTENT_TYPE, 'img/svg+xml', $m)) echo $m[1], "\n";
if (preg_match(RE_CONTENT_TYPE, 'audio/mp3', $m)) echo $m[1], "\n";
if (preg_match(RE_CONTENT_TYPE, 'multipart/mixed ;boundary="PHOTE DAURTAUGRAF"', $m)) echo $m[1], "\n";
//*/

?>