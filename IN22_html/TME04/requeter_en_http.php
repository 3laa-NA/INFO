<?php

include "/home/alaana/INFO-main/IN22_html/TME02/re_url.php";
include "/home/alaana/INFO-main/IN22_html/TME04/re_http_status.php";
include "/home/alaana/INFO-main/IN22_html/TME04/http_args.php";
include "/home/alaana/INFO-main/IN22_html/TD04/lire_entetes.php";

function requeter_en_http($url, $req = 'GET', $version = "1.1", $entetes = array()){

    if(!preg_match(RE_URL, $url, $m)) return aray(400, $array(), "URL incorecte!!!\r\n");

    ($m[3] != '')? $port = $m[3]: $port = 80;

    $sock = fsockopen( $m[2], $port);

    if(!$sock){
        return array(500, array(), "erreur de connexion!!!\r\n");
    }

    fputs($sock, $req . $url . http_args($m[2], $entetes, $version));

    preg_match(RE_HTTP_STATUS, fgets($sock), $t);

    $tab_entetes = array();
    $code = 200;

    if($t[1] != ''){
        $tab_entetes = lire_entetes($sock);
        $code = $t[2];
    }

    $reste = '';

    while(!feof($sock)){
        $reste .= fgets($sock);
    }

    return array($code, $tab_entetes, $reste);

}

?>